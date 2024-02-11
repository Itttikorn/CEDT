--DATABASE CREATION
CREATE DATABASE HotelBookingDatabase

--TABLE CREATION
CREATE TABLE users (
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
    FOREIGN KEY (userId) REFERENCES users (userId),
    FOREIGN KEY (roomId,hotelID) REFERENCES Room(roomId,hotelID),
    PRIMARY KEY (bookingId)
);

CREATE TABLE Admin (
    userId INTEGER NOT NULL,
    hotelId INTEGER NOT NULL,
    FOREIGN KEY (userId) REFERENCES users(userId),
    FOREIGN KEY (hotelId) REFERENCES Hotel(hotelId)
);

CREATE TABLE loggedin (
    logId SERIAL,
    userID INTEGER NOT NULL,
    email VARCHAR(255),
    logType VARCHAR(6),
    loggedtime TIMESTAMP,
    PRIMARY KEY (logId),
    FOREIGN KEY (userId) REFERENCES users(userId)
);

-- Sample Data
INSERT INTO users (userID, firstName, lastName, email, passcode, telephoneNumber)
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