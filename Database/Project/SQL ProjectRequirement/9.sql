CREATE OR REPLACE PROCEDURE admin_delete_booking(
    adminuserID INTEGER,
    deletebookingID INTEGER
)
    LANGUAGE plpgsql    
    AS
$$
DECLARE
    adminId INTEGER;
BEGIN 
    SELECT admin.userId
    INTO adminId
    FROM admin
    WHERE admin.userId = adminuserId;

    IF NOT FOUND THEN
        RETURN;
    ELSE
        DELETE FROM booking WHERE booking.bookingId = deletebookingID;
        RETURN;
    END IF;
END;
$$

--Test Functions
CALL admin_delete_booking(2,2);
SELECT * FROM booking