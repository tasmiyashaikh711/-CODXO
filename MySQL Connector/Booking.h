// Booking.h
#include "DatabaseConnector.h"
#include <vector>

class Booking {
public:
    int booking_id;
    int room_id;
    int guest_id;
    std::string checkin_date;
    std::string checkout_date;
    std::string status;

    static std::vector<Booking> getAllBookings(DatabaseConnector& db);
    static void addBooking(DatabaseConnector& db, int room_id, int guest_id, const std::string& checkin, const std::string& checkout);
};

// Booking.cpp
#include "Booking.h"

std::vector<Booking> Booking::getAllBookings(DatabaseConnector& db) {
    std::vector<Booking> bookings;
    sql::Connection* conn = db.connect();
    sql::Statement* stmt = conn->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM bookings");

    while (res->next()) {
        Booking booking;
        booking.booking_id = res->getInt("booking_id");
        booking.room_id = res->getInt("room_id");
        booking.guest_id = res->getInt("guest_id");
        booking.checkin_date = res->getString("checkin_date");
        booking.checkout_date = res->getString("checkout_date");
        booking.status = res->getString("status");
        bookings.push_back(booking);
    }
    delete res;
    delete stmt;
    return bookings;
}

void Booking::addBooking(DatabaseConnector& db, int room_id, int guest_id, const std::string& checkin, const std::string& checkout) {
    sql::Connection* conn = db.connect();
    sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO bookings(room_id, guest_id, checkin_date, checkout_date, status) VALUES (?, ?, ?, ?, 'confirmed')");
    pstmt->setInt(1, room_id);
    pstmt->setInt(2, guest_id);
    pstmt->setString(3, checkin);
    pstmt->setString(4, checkout);
    pstmt->execute();
    delete pstmt;
}
