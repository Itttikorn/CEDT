-- 5. The system shall allow the registered user to edit his hotel bookings.
CREATE OR REPLACE PROCEDURE edit_hotel_bookings(
    booking_ID INTEGER,
    booking_status VARCHAR,
    start_date DATE,
    end_date DATE,
    creationdate TIMESTAMP,
    room_id INTEGER,
    hotel_id INTEGER
)
    LANGUAGE plpgsql
    AS
$$
DECLARE
    realhotelID INTEGER;
BEGIN 
    UPDATE booking SET bookingStatus = booking_status,
                        startdate = start_date,
                        enddate = end_date,
                        creation_date = NOW(),
                        roomid = room_id,
                        hotelid = hotel_id
        
        WHERE bookingID = booking_ID;
        RETURN;
END;
$$

--Test Functions
CALL edit_hotel_bookings(1::INTEGER, 2::VARCHAR, '2024-03-01'::DATE, '2024-03-10'::DATE, NOW()::TIMESTAMP, 2::INTEGER, 1::INTEGER);
SELECT * FROM booking