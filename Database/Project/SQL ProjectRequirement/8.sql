-- 8. The system shall allow the admin to edit any hotel bookings.
CREATE OR REPLACE PROCEDURE admin_edit_booking(
    booking_ID INTEGER,
    booking_Status VARCHAR,
    start_date DATE,
    end_date DATE,
    creationdate TIMESTAMP,
    room_id INTEGER,
    edituser INTEGER
)
    LANGUAGE plpgsql
    AS
$$
DECLARE
    realhotelID INTEGER;
BEGIN 
    SELECT Admin.hotelID
    INTO realhotelID
    FROM Admin
    WHERE Admin.userID = edituser;

    IF NOT FOUND THEN
        RETURN;
    ELSE
        UPDATE booking set bookingStatus = booking_Status,
                            startdate = start_date,
                            enddate = end_date,
                            creation_date = NOW(),
                            roomid = room_id
        
        where bookingID = booking_ID;
        RETURN;
    END IF;
END;
$$

--Test Functions
CALL admin_edit_booking(2::INTEGER, 2::VARCHAR, '2024-03-01'::DATE, '2024-03-10'::DATE, NOW()::TIMESTAMP, 4::INTEGER, 2::INTEGER);
SELECT * FROM booking