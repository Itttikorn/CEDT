--DATABASE CREATION
CREATE DATABASE HotelBookingDatabase

--TABLE CREATION
CREATE TABLE UserName (
    userId SERIAL NOT NULL,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,

    email VARCHAR(255) NOT NULL UNIQUE,
    passcode VARCHAR(255) NOT NULL,
    telephoneNumber VARCHAR(10) NOT NULL,
    PRIMARY KEY (userId)
);

CREATE TABLE Hotel (
    hotelId SERIAL NOT NULL,
    name VARCHAR(255) NOT NULL,
    telephoneNumber VARCHAR(10) NOT NULL,
    email VARCHAR(255),
    buildingNo VARCHAR(10) NOT NULL,
    street VARCHAR(255),
    subDistrictName VARCHAR(255) NOT NULL,
    districtName VARCHAR(255) NOT NULL,
    province VARCHAR(255) NOT NULL,
    postalCode VARCHAR(5) NOT NULL,
    PRIMARY KEY (hotelId)
);



CREATE TABLE RoomType (
    typeName VARCHAR(255) NOT NULL,
    maxOccupant INTEGER NOT NULL,
    amenities VARCHAR(255) NOT NULL,
    price INTEGER NOT NULL,
    PRIMARY KEY (typeName)
);

CREATE TABLE Room (
    hotelId SERIAL NOT NULL,
    roomId SERIAL NOT NULL,
    roomnumber INTEGER NOT NULL,
    roomstatus VARCHAR(255) NOT NULL,
    typeName VARCHAR(255) NOT NULL,
    PRIMARY KEY (hotelId,roomId),
    FOREIGN KEY (typeName) REFERENCES RoomType(typeName)
);

CREATE TABLE Review (
    reviewID SERIAL NOT NULL,
    messages VARCHAR(255),
    rating NUMERIC NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (hotelId) REFERENCES Hotel(hotelId)
);

CREATE TABLE Booking (
    userId INTEGER NOT NULL,
    bookingId SERIAL NOT NULL,
    bookingStatus VARCHAR(255) NOT NULL,
    startDate DATE NOT NULL,
    enddate DATE NOT NULL,
    creation_Date TIMESTAMP NOT NULL,
    roomId INTEGER NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (userId) REFERENCES UserName (userId),
    FOREIGN KEY (roomId,hotelID) REFERENCES Room(roomId,hotelID),
    PRIMARY KEY (bookingId)
);

CREATE TABLE Admin (
    userId INTEGER NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (userId) REFERENCES UserName(userId),
    FOREIGN KEY (hotelId) REFERENCES Hotel(hotelId)
);

CREATE TABLE loggedin (
    logId SERIAL,
    userID INTEGER NOT NULL,
    email VARCHAR(255),
    logType VARCHAR(6),
    loggedtime TIMESTAMP,
    PRIMARY KEY (logId),
    FOREIGN KEY (userId) REFERENCES UserName(userId)
);

-- Sample Data
INSERT INTO UserName (userID, firstName, lastName, email, passcode, telephoneNumber)
VALUES 
    (DEFAULT, 'John', 'Doe', 'john.doe@example.com', 'password123', '1234567890'),
    (DEFAULT, 'Jane', 'Smith', 'jane.smith@example.com', 'pass123', '9876543210'),
    (DEFAULT, 'Michael', 'Johnson', 'michael.j@example.com', 'mikepass', '5554443333'),
    (DEFAULT, 'Emily', 'Davis', 'emily.d@example.com', 'emilypass', '1112223333'),
    (DEFAULT, 'Daniel', 'Brown', 'daniel.b@example.com', 'danpass', '9998887777');

INSERT INTO Hotel (hotelId, name, telephoneNumber, email, buildingNo, street, subDistrictName, districtName, province, postalCode)
VALUES 
    (DEFAULT, 'Luxury Hotel', '1112223333', 'info@luxuryhotel.com', '123', 'Main Street', 'Downtown', 'Cityville', 'Bangkok', '12345'),
    (DEFAULT, 'Cozy Inn', '4445556666', 'info@cozyinn.com', '456', 'Side Street', 'Suburb', 'Villagetown', 'Bangkok', '67890'),
    (DEFAULT, 'Sunset Resort', '7778889999', 'info@sunsetresort.com', '789', 'Beach Road', 'Seaside', 'Oceanview', 'Bangkok', '54321'),
    (DEFAULT, 'Mountain Lodge', '3336669999', 'info@mountainlodge.com', '567', 'Hilltop Avenue', 'Hillside', 'Mountainville', 'Bangkok', '87654'),
    (DEFAULT, 'City Center Suites', '2224446666', 'info@citycentersuites.com', '890', 'Central Street', 'City Central', 'Downtown', 'Bangkok', '23456');

INSERT INTO RoomType (typeName, maxOccupant, amenities, price)
VALUES 
    ('Standard', 2, 'TV, Wifi', 100),
    ('Suite', 4, 'TV, Wifi, Jacuzzi', 200),
    ('Deluxe', 3, 'TV, Wifi, Mini-bar', 150),
    ('Family', 6, 'TV, Wifi, Kitchenette', 250),
    ('Executive Suite', 5, 'TV, Wifi, Conference Room', 300);

INSERT INTO Room (hotelId, roomId, roomnumber, roomstatus, typeName)
VALUES 
    (1, DEFAULT, 101, 'Available', 'Standard'),
    (1, DEFAULT, 102, 'Available', 'Suite'),
    (2, DEFAULT, 201, 'Available', 'Deluxe'),
    (2, DEFAULT, 202, 'Available', 'Family'),
    (3, DEFAULT, 301, 'Available', 'Executive Suite'),
    (4, DEFAULT, 401, 'Available', 'Standard'),
    (4, DEFAULT, 402, 'Available', 'Deluxe'),
    (5, DEFAULT, 501, 'Available', 'Suite'),
    (5, DEFAULT, 502, 'Available', 'Family');

INSERT INTO Review (reviewID, messages, rating, hotelId)
VALUES 
    (DEFAULT, 'Great experience!', 4.5, 1),
    (DEFAULT, 'Friendly staff and clean rooms', 5.0, 2),
    (DEFAULT, 'Beautiful beach view', 4.0, 3),
    (DEFAULT, 'Serene mountain retreat', 4.5, 4),
    (DEFAULT, 'Central location, good amenities', 3.8, 5);

INSERT INTO Booking (userId, bookingId, bookingStatus, startDate, enddate, creation_Date, roomId, hotelId)
VALUES 
    (1, DEFAULT, 1, '2024-02-01', '2024-02-05', '2024-01-15 10:00:00', 1, 1),
    (2, DEFAULT, 1, '2024-03-01', '2024-03-10', '2024-02-01 12:30:00', 3, 2),
    (3, DEFAULT, 1, '2024-04-15', '2024-04-20', '2024-03-01 08:45:00', 5, 3),
    (4, DEFAULT, 1, '2024-05-10', '2024-05-15', '2024-04-01 15:20:00', 7, 4),
    (5, DEFAULT, 1, '2024-06-01', '2024-06-10', '2024-05-01 09:30:00', 9, 5);

INSERT INTO Admin (userId, hotelId)
VALUES 
    (1, 1),
    (2, 2);

-- Project Requirements
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
    FROM UserName u
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
    FROM UserName u
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
FROM Booking B, UserName U, Room R, Hotel H
WHERE B.userID = Inuserid and  B.roomID = R.roomID and H.hotelID = B.hotelID;


END;
$$

--Test Functions
SELECT * FROM view_hotel_bookings(1)

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
FROM Booking B, UserName U, Room R
WHERE B.userID = U.userID and B.hotelID = userhotelID and B.roomID = R.roomID;


END;
$$

--Test Functions
SELECT * FROM admin_view_booking(2);

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

-- 9. The system shall allow the admin to delete any hotel bookings
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

-- Complex Query Scenario
-- แสดง ราคาเฉลี่ยของ hotel ที่อยู่ในจังหวัด กรุงเทพ ที่มี rating มากกว่า 4.0 มา 3 อันดับแรก โดยเรียงจากมากไปน้อย โดยนำข้อมูล rating จาก Review 
-- ที่มี hotelId ตรงกับ hotelId ที่ต้องการหา
SELECT h.name AS HotelName, ROUND(AVG(rt.price),2) AS AveragePrice
FROM Hotel h
JOIN Room ro ON h.hotelId = ro.hotelId
JOIN Review re ON h.hotelId = re.hotelId
JOIN RoomType rt ON ro.typeName = rt.typeName
WHERE h.province = 'Bangkok' AND re.rating > 4.0
GROUP BY h.hotelId, h.name
ORDER BY AVG(rt.price) DESC
LIMIT 3;

