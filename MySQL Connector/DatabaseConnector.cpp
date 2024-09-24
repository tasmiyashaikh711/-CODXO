//Database Connector (DatabaseConnector.h / DatabaseConnector.cpp)

// DatabaseConnector.h
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

class DatabaseConnector {
public:
    DatabaseConnector();
    ~DatabaseConnector();
    sql::Connection* connect();
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* conn;
};

// DatabaseConnector.cpp
#include "DatabaseConnector.h"

DatabaseConnector::DatabaseConnector() {
    driver = sql::mysql::get_mysql_driver_instance();
    conn = nullptr;
}

DatabaseConnector::~DatabaseConnector() {
    delete conn;
}

sql::Connection* DatabaseConnector::connect() {
    conn = driver->connect("tcp://127.0.0.1:3306", "root", "password");
    conn->setSchema("HotelManagement");
    return conn;
}
