-- 3. After login, the system shall allow the registered user to book up to 3 nights by
-- specifying the date and the preferred hotel. The hotel list is also provided to the user. A
-- hotel information includes the hotel name, address, and telephone number.

--Checking if the date specified is <= 3 nights.
CREATE OR REPLACE FUNCTION hotel_list(
    in_startDate DATE,
    in_endDate DATE)
RETURNS TABLE(
    HotelName VARCHAR,
    RoomType VARCHAR,
    buildingNo VARCHAR,
    street VARCHAR,
    subDistrictName VARCHAR,
    districtName VARCHAR,
    province VARCHAR,
    postalCode VARCHAR,
    email VARCHAR 
)
LANGUAGE plpgsql
AS $$
BEGIN
    IF (in_endDate - in_startDate) <= 4 THEN
        RETURN QUERY
        SELECT h.name,
               rt.typeName,
               h.buildingNo,
               h.street,
               h.subDistrictName,
               h.districtName,
               h.province,
               h.postalCode,
               h.email
        FROM room R
        JOIN Hotel h ON R.hotelId = h.hotelId
        JOIN RoomType rt ON R.typeName = rt.typeName
        WHERE NOT EXISTS (
            SELECT 1
            FROM Booking b
            WHERE R.roomId = b.roomId
              AND h.hotelId = b.hotelId
              AND ((in_startDate BETWEEN b.startDate AND b.endDate) OR (in_endDate BETWEEN b.startDate AND b.endDate))
        );
    ELSE
        RETURN NEXT;
    END IF;
END;
$$;

--Testing  Functions
SELECT * from hotel_list('2023-02-01'::DATE, '2023-02-02'::DATE);

-- Book Hotel
CREATE OR REPLACE FUNCTION booking_hotel(
    in_startDate DATE,
    in_enddate DATE,
    hotel_id INTEGER,
    room_id INTEGER,
    user_Id INTEGER
)
RETURNS BOOLEAN
LANGUAGE plpgsql
AS $$
BEGIN
    INSERT INTO booking VALUES(user_Id, DEFAULT, 1,in_startdate, in_enddate, NOW(), room_id, hotel_id);
    RETURN TRUE;
END $$

--Testing Functions
SELECT * FROM booking_hotel('2023-02-01'::DATE, '2023-02-02'::DATE, 1::INTEGER, 1::INTEGER, 1::INTEGER);