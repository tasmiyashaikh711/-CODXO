
CREATE DATABASE HotelManagement;

USE HotelManagement;

CREATE TABLE rooms (
  room_id INT AUTO_INCREMENT PRIMARY KEY,
  room_type VARCHAR(50),
  status VARCHAR(20),
  price DECIMAL(10, 2)
);

CREATE TABLE guests (
  guest_id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(100),
  contact_info VARCHAR(255)
);

CREATE TABLE bookings (
  booking_id INT AUTO_INCREMENT PRIMARY KEY,
  room_id INT,
  guest_id INT,
  checkin_date DATE,
  checkout_date DATE,
  status VARCHAR(20),
  FOREIGN KEY (room_id) REFERENCES rooms(room_id),
  FOREIGN KEY (guest_id) REFERENCES guests(guest_id)
);
