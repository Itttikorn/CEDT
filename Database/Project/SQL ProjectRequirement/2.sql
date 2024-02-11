-- 2. After registration, the user becomes a registered user, and the system shall allow the
-- user to login to use the system by specifying the email and password. The system shall
-- allow a registered user to log out.
CREATE OR REPLACE FUNCTION log_in(
    emaill VARCHAR,
    passcodee VARCHAR)
    RETURNS BOOLEAN
    LANGUAGE plpgsql
    AS
$$
DECLARE
    realpasscode VARCHAR(255);
    realuserID INTEGER;
BEGIN
    SELECT u.passcode, u.userID
    INTO realpasscode,realuserID
    FROM users u
    WHERE u.email = emaill;
    
    IF NOT FOUND THEN 
        RETURN FALSE;
    ELSE
        IF realpasscode = passcodee THEN
            INSERT INTO loggedin VALUES (DEFAULT, realuserID, emaill,'login', now());
            RETURN TRUE;
        ELSE
            RETURN FALSE;
        END IF;
    END IF;
END;
$$
 

CREATE OR REPLACE PROCEDURE log_out(
    emaill VARCHAR
    )
    LANGUAGE plpgsql
    AS
$$
DECLARE
    realuserID INTEGER;
BEGIN
    SELECT u.userID
    INTO realuserID
    FROM users u
    WHERE u.email = emaill;
    INSERT INTO loggedin VALUES (DEFAULT, realuserID, emaill,'logout', now());
    COMMIT;
END;
$$

-- Test Functions
SELECT log_in('john.doe@example.com', 'password123') -- Return TRUE
SELECT log_in('john.doe@example.com', 'incorrectpass') -- Return FALSE
SELECT * FROM loggedin;

CALL log_out('john.doe@example.com')
SELECT * FROM loggedin;