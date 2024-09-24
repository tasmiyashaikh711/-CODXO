#include "DatabaseConnector.h"
#include "Room.h"
#include "Booking.h"
#include <iostream>

int main() {
    DatabaseConnector db;

    // List all rooms
    std::vector<Room> rooms = Room::getAllRooms(db);
    std::cout << "Available Rooms:" << std::endl;
    for (const auto& room : rooms) {
        std::cout << "Room ID: " << room.room_id << ", Type: " << room.room_type << ", Price: $" << room.price << std::endl;
    }

    // Booking Example
    Booking::addBooking(db, 1, 1, "2024-10-01", "2024-10-05");

    return 0;
}
