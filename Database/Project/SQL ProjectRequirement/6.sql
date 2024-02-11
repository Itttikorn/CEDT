-- 6. The system shall allow the registered user to delete his hotel bookings.
CREATE OR REPLACE PROCEDURE delete_hotel_bookings(
    userID INTEGER, booking_ID INTEGER
)
LANGUAGE plpgsql
AS $$
BEGIN 
    DELETE FROM booking B where booking_ID = B.bookingID;
END;
$$

--Test Functions
CALL delete_hotel_bookings(1,1);
SELECT * from booking;