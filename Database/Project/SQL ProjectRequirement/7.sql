-- 7. The system shall allow the admin to view any hotel bookings.
CREATE OR REPLACE FUNCTION admin_view_booking(
    Inuserid INTEGER
)
RETURNS TABLE(
    bookingID INTEGER,
    firstname VARCHAR,
    lastname VARCHAR,
    bookingStatus VARCHAR,
    startDate DATE,
    endDate DATE,
    RoomType VARCHAR
    )
LANGUAGE plpgsql
AS $$
DECLARE 
    userhotelID INTEGER;
BEGIN
SELECT A.hotelID
INTO userhotelID
FROM Admin A
WHERE InuserID = A.UserID;

IF NOT FOUND THEN
    RETURN NEXT;
END IF;

RETURN QUERY
SELECT DISTINCT B.bookingID, U.firstname, U.lastname, B.bookingStatus, B.startDate, B.endDate, R.typeName
FROM Booking B, users U, Room R
WHERE B.userID = U.userID and B.hotelID = userhotelID and B.roomID = R.roomID;


END;
$$

--Test Functions
SELECT * FROM admin_view_booking(2);