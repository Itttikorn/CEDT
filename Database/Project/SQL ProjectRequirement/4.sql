-- 4. The system shall allow the registered user to view his hotel bookings.
CREATE OR REPLACE FUNCTION view_hotel_bookings(
    Inuserid INTEGER
)
RETURNS TABLE(
    bookingID INTEGER,
    bookingStatus VARCHAR,
    startDate DATE,
    endDate DATE,
    RoomType VARCHAR,
    Hotelname VARCHAR
    )
LANGUAGE plpgsql
AS $$
 
BEGIN

RETURN QUERY
SELECT DISTINCT B.bookingID, B.bookingStatus, B.startDate, B.endDate, R.typeName, H.name
FROM Booking B, users U, Room R, Hotel H
WHERE B.userID = Inuserid and  B.roomID = R.roomID and H.hotelID = B.hotelID;


END;
$$

--Test Functions
SELECT * FROM view_hotel_bookings(1)