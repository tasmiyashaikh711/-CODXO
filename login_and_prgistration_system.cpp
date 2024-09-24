#include<iostream>
#include<string>
#include<vector>

using namespace std;

class User {
private:
    string username, password;
    
public:
    User(string name, string pass) {  // Constructor
        username = name;
        password = pass;
    }

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    void displayUser() {
        cout << "\tUsername: " << username << endl;
    }
};

class UserManager {
private:
    vector<User> users;  // Vector to store users

public:
    // Register a new user
    void RegisterUser() {
        string username, password;
        cout << "\n\tEnter Username: ";
        cin >> username;
        cout << "\n\tEnter Password: ";
        cin >> password;

        User newUser(username, password);
        users.push_back(newUser);

        cout << "\n\n\tUser registered successfully!" << endl;
    }

    // Login functionality
    void Login() {
        string username, password;
        cout << "\n\tEnter Username: ";
        cin >> username;
        cout << "\n\tEnter Password: ";
        cin >> password;

        for (auto &user : users) {
            if (user.getUsername() == username && user.getPassword() == password) {
                cout << "\n\n\tLogin successful! Welcome, " << username << "!" << endl;
                return;
            }
        }
        cout << "\n\n\tInvalid username or password!" << endl;
    }

    // Display the list of all registered users
    void ShowUserList() {
        cout << "\n\tList of registered users:" << endl;
        for (auto &user : users) {
            user.displayUser();
        }
    }

    // Search for a user by username
    void SearchUser() {
        string username;
        cout << "\n\tEnter Username to search: ";
        cin >> username;

        for (auto &user : users) {
            if (user.getUsername() == username) {
                cout << "\n\tUser found:" << endl;
                user.displayUser();
                return;
            }
        }
        cout << "\n\tUser not found!" << endl;
    }

    // Delete a user by username
    void DeleteUser() {
        string username;
        cout << "\n\tEnter Username to delete: ";
        cin >> username;

        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->getUsername() == username) {
                users.erase(it);
                cout << "\n\tUser deleted successfully!" << endl;
                return;
            }
        }
        cout << "\n\tUser not found!" << endl;
    }
};

int main() {
    UserManager userManager;
    int option;

    while (true) {
        cout << "\n\n\t\t1. Register user" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show User List" << endl;
        cout << "\t\t4. Search user" << endl;
        cout << "\t\t5. Delete user" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            userManager.RegisterUser();
            break;
        case 2:
            userManager.Login();
            break;
        case 3:
            userManager.ShowUserList();
            break;
        case 4:
            userManager.SearchUser();
            break;
        case 5:
            userManager.DeleteUser();
            break;
        case 6:
            cout << "\n\tExiting the program..." << endl;
            return 0;
        default:
            cout << "\n\tInvalid option! Please try again." << endl;
        }
    }

    return 0;
}
