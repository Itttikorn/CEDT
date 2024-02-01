CREATE TYPE RoomType AS ENUM('Standard', 'Suite', 'Deluxe', 'Family');
CREATE TYPE RoomStatus AS ENUM('Occupied', 'Available','Not-Available');
CREATE TYPE BookingStatus AS ENUM('Created', 'Paid', 'Cancelled', 'Checked-in');

CREATE TABLE User (
    userId INTEGER NOT NULL,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,

    email VARCHAR(255) NOT NULL,
    passcode VARCHAR(255) NOT NULL,
    telephoneNumber VARCHAR(10) NOT NULL,
    PRIMARY KEY (userId)
);

CREATE TABLE Hotel (
    hotelId INTEGER NOT NULL,
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

CREATE TABLE Room (
    hotelId INTEGER NOT NULL,
    roomId INTEGER NOT NULL,
    roomnumber INTEGER NOT NULL,
    roomstatus VARCHAR(255) NOT NULL,
    typeName VARCHAR(255) NOT NULL,
    PRIMARY KEY (hotelId,roomId),
    FOREIGN KEY (typeName) REFERENCES RoomType(typeName)
);

CREATE TABLE RoomType (
    typeName VARCHAR(255) NOT NULL,
    maxOccupant INTEGER NOT NULL,
    amenities VARCHAR(255) NOT NULL,
    price INTEGER NOT NULL
);

CREATE TABLE Review (
    reviewID INTEGER NOT NULL,
    messages VARCHAR(255),
    rating NUMERIC NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (hotelId) REFERENCES Hotel(hotelId)
);

CREATE TABLE Booking (
    userId INTEGER NOT NULL,
    bookingId INTEGER NOT NULL,
    my_status INTEGER NOT NULL,
    startDate DATE NOT NULL,
    enddate DATE NOT NULL,
    creation_Date TIMESTAMP NOT NULL,
    roomId INTEGER NOT NULL,
    hotelId INTEGER NOT NULL
    FOREIGN KEY (userId) REFERENCES User(userId),
    FOREIGN KEY (roomId) REFERENCES Room(roomId),
    FOREIGN KEY (hotelId) REFERENCES Room(hotelId),
    PRIMARY KEY (bookingId)
);

CREATE TABLE Admin (
    userId INTEGER NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (userId) REFERENCES User(userId),
    FOREIGN KEY (hotelId) REFERENCES Room(hotelId)
);

-- 1. The system shall allow a user to register by specifying the name, telephone number,
-- email, and password.
-- 2. After registration, the user becomes a registered user, and the system shall allow the
-- user to log in to use the system by specifying the email and password. The system shall
-- allow a registered user to log out.
-- 3. After login, the system shall allow the registered user to book up to 3 nights by
-- specifying the date and the preferred hotel. The hotel list is also provided to the user. A
-- hotel information includes the hotel name, address, and telephone number.
-- 4. The system shall allow the registered user to view his hotel bookings.
-- 5. The system shall allow the registered user to edit his hotel bookings.
-- 6. The system shall allow the registered user to delete his hotel bookings.
-- 7. The system shall allow the admin to view any hotel bookings.
-- 8. The system shall allow the admin to edit any hotel bookings.
-- 9. The system shall allow the admin to delete any hotel bookings

-- Scenario
-- แสดง ราคาเฉลี่ยของ hotel ที่อยู่ในจังหวัด กรุงเทพ ที่มี rating มากกว่า 4.0 มา 3 อันดับแรก โดยเรียงจากมากไปน้อย โดยนำข้อมูล rating จาก Review 
-- ที่มี hotelId ตรงกับ hotelId ที่ต้องการหา
SELECT h.hotelName, AVG(R.rating)
FROM Hotel H JOIN Review R
ON H.hotelId = R.hotelId
GROUP BY H.hotelId
HAVING AVG(R.rating) > 4.0
ORDER BY AVG(R.rating) DESC LIMIT 3;

