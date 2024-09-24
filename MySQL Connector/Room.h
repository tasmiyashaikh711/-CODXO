// Room.h
#include "DatabaseConnector.h"
#include <vector>

class Room {
public:
    int room_id;
    std::string room_type;
    std::string status;
    double price;

    static std::vector<Room> getAllRooms(DatabaseConnector& db);
    static void addRoom(DatabaseConnector& db, const std::string& type, double price);
};

// Room.cpp
#include "Room.h"

std::vector<Room> Room::getAllRooms(DatabaseConnector& db) {
    std::vector<Room> rooms;
    sql::Connection* conn = db.connect();
    sql::Statement* stmt = conn->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM rooms");

    while (res->next()) {
        Room room;
        room.room_id = res->getInt("room_id");
        room.room_type = res->getString("room_type");
        room.status = res->getString("status");
        room.price = res->getDouble("price");
        rooms.push_back(room);
    }
    delete res;
    delete stmt;
    return rooms;
}

void Room::addRoom(DatabaseConnector& db, const std::string& type, double price) {
    sql::Connection* conn = db.connect();
    sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO rooms(room_type, status, price) VALUES (?, 'available', ?)");
    pstmt->setString(1, type);
    pstmt->setDouble(2, price);
    pstmt->execute();
    delete pstmt;
}
