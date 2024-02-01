CREATE TABLE address_audit_log (customer_street VARCHAR NOT NULL, exec_time timestamp NOT NULL);
 
CREATE OR REPLACE FUNCTION log_address_history()
RETURNS TRIGGER
language plpgsql
AS $$
BEGIN
  INSERT INTO address_audit_log VALUES(OLD.customer_street, now());
  RETURN NEW;
END;$$
 
CREATE OR REPLACE TRIGGER updating_new_address
BEFORE UPDATE ON customer
FOR EACH ROW
EXECUTE PROCEDURE log_address_history();

SELECT * FROM customer;

SELECT * FROM address_audit_log;

UPDATE customer
SET customer_street = 'Main_street2'
WHERE customer_name = 'Alan';

SELECT * FROM address_audit_log;

SELECT * FROM customer;