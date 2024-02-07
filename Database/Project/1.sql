-- 1. The system shall allow a user to register by specifying the name, telephone number,
-- email, and password.
CREATE OR REPLACE FUNCTION add_user (
    firstname VARCHAR(255), 
    lastname VARCHAR(255), 
    emaill VARCHAR(255),
    passcode VARCHAR(255),
    telephoneNumber VARCHAR(10))
    RETURNS BOOLEAN
    LANGUAGE plpgsql
    AS
$$
DECLARE 
	checkemail VARCHAR(255);
    rn INTEGER;
BEGIN
	SELECT userName.email
	INTO checkemail
	FROM userName
	WHERE emaill = userName.email;
	
    IF FOUND THEN
        RETURN FALSE;
    END IF;
    
    INSERT INTO UserName VALUES
    (DEFAULT, firstname, lastname, emaill, passcode, telephoneNumber);
	
	RETURN TRUE;

END;
$$
-- Test functions
SELECT add_user('John', 'Doe', 'john.doe@example.com', 'password123', '1234567890'); -- RETURN FALSE due to same email
SELECT add_user('John', 'Doe', 'alice.j@example.com', 'password123', '1234567890'); -- RETURN TRUE