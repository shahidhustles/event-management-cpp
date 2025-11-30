 // ========================================
// MAIN.CPP - Application Entry Point
// ========================================
// This is the heart of the application where everything starts.
// It handles user login, menu navigation, and coordinates between Admin and Student classes.
// Key OOP concepts demonstrated: Polymorphism, Dynamic Casting, Pointer Management

#include "user.h"       // Base User class
#include "admin.h"      // Admin class (inherits from User)
#include "student.h"    // Student class (inherits from User)
#include "utils.h"      // Utility functions (split, trim, etc.)
#include <iostream>     // For input/output (cin, cout)
#include <fstream>      // For file operations (ifstream, ofstream)
#include <vector>       // For dynamic arrays (vector)

using namespace std;    // Avoids writing std:: before cout, cin, string, etc.

// ==================== AUTHENTICATION ====================

// Function to load users from file and authenticate
// What it does: Reads users.txt, checks if username/password match, creates appropriate User object
// Returns: Pointer to Admin or Student object if login successful, nullptr if failed
// Return type is User* (base class pointer) which can point to Admin or Student objects (polymorphism)
User* authenticateUser(string username, string password) {
    // Open the users.txt file for reading
    // ifstream = "input file stream" (for reading from files)
    ifstream file("data/users.txt");
    string line, uname, pass, name, type;    // Variables to store file data
    
    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Error: Could not open users.txt file!" << endl;
        cout << "Please ensure users.txt exists with proper user data." << endl;
        return nullptr;    // nullptr = null pointer (no valid user)
    }
    
    cout << "Checking credentials..." << endl;
    
    // File format: username,password,fullname,usertype
    // Example line: "john,pass123,John Doe,student"
    
    // Read file line by line
    while (getline(file, line)) {
        if (line.empty()) continue;    // Skip empty lines
        
        // Split the line by comma to get individual fields
        vector<string> parts = split(line, ',');    // split() is from utils.cpp
        
        // Ensure we have all required fields (at least 4 parts)
        if (parts.size() >= 4) {
            // Extract and clean each field (remove whitespace)
            uname = trim(parts[0]);    // Username
            pass = trim(parts[1]);     // Password
            name = trim(parts[2]);     // Full name
            type = trim(parts[3]);     // User type (admin/student)
            
            // Check if credentials match what the user entered
            if (uname == username && pass == password) {
                file.close();    // Close the file before returning
                
                // POLYMORPHISM IN ACTION!
                // We return a User* pointer, but it actually points to Admin or Student object
                // This allows different behaviors based on user type
                if (type == "admin") {
                    cout << "Admin access granted!" << endl;
                    // 'new' creates an Admin object on the heap (dynamic memory allocation)
                    return new Admin(uname, pass, name);
                } else if (type == "student") {
                    cout << "Student access granted!" << endl;
                    // 'new' creates a Student object on the heap
                    return new Student(uname, pass, name);
                }
            }
        }
    }
    
    // If we reach here, no matching credentials were found
    file.close();
    return nullptr;    // Return null pointer to indicate authentication failed
}

// ==================== WELCOME MESSAGE ====================

// Display welcome banner with system features
// What it does: Shows a nice welcome screen when the program starts
void displayWelcome() {
    cout << "\n=================================================" << endl;
    cout << "   COLLEGE EVENT MANAGEMENT SYSTEM   " << endl;
    cout << "=================================================" << endl;
    cout << "Features available :" << endl;
    cout << "• User Authentication (Admin/Student)" << endl;
    cout << "• Role-based Menu Systems" << endl;
    cout << "• CRUD Operations on Events" << endl;
    cout << "• Event Registration & Management" << endl;
    cout << "• Search & Filter Events" << endl;
    cout << "• Registration Reports" << endl;
    cout << "• User Management (Admin)" << endl;
    cout << "=================================================" << endl;
}

// ==================== MAIN APPLICATION ====================

// Main function - Program execution starts here
// What it does: Handles login, shows menus, processes user choices, and cleans up
// Return value: 0 means success, 1 means error/failure
int main() {
    // Show welcome message first
    displayWelcome();
    
    // Declare variables for login
    string username, password;
    User* currentUser = nullptr;    // Pointer to store logged-in user (base class pointer)
    int loginAttempts = 0;          // Track how many login attempts
    const int maxAttempts = 3;      // 'const' means this value can't be changed
    
    // Login loop with attempt limit
    // Loop continues while: user not logged in AND attempts haven't exceeded limit
    while (currentUser == nullptr && loginAttempts < maxAttempts) {
        cout << "\n=== LOGIN SYSTEM ===" << endl;
        cout << "Default credentials for testing:" << endl;
        cout << "Admin: admin / admin123" << endl;
        cout << "Student: john / pass123" << endl;
        cout << "        alice / alice456" << endl;
        cout << "        bob / bob789" << endl;
        cout << "========================" << endl;
        
        // Get credentials from user
        cout << "Username: ";
        cin >> username;    // Read username (stops at whitespace)
        cout << "Password: ";
        cin >> password;
        
        // Try to authenticate
        currentUser = authenticateUser(username, password);
        loginAttempts++;    // Increment attempt counter
        
        // If authentication failed (nullptr returned)
        if (currentUser == nullptr) {
            cout << "Invalid credentials! " << endl;
            
            // Show remaining attempts if not the last attempt
            if (loginAttempts < maxAttempts) {
                cout << "Attempts remaining: " << (maxAttempts - loginAttempts) << endl;
                cout << "Please try again." << endl;
            }
        }
    }
    
    // Check if login attempts exceeded (still no valid user)
    if (currentUser == nullptr) {
        cout << "Maximum login attempts exceeded. Access denied!" << endl;
        return 1;    // Exit program with error code
    }
    
    // Main application loop after successful authentication
    cout << "\n*** LOGIN SUCCESSFUL ***" << endl;
    
    // POLYMORPHISM: getUserType() returns "Admin" or "Student" depending on actual object type
    cout << "User Type: " << currentUser->getUserType() << endl;
    cout << "Welcome, " << currentUser->getFullName() << "!" << endl;
    
    int choice;             // Store menu choice
    bool running = true;    // Control main loop
    
    // Main menu loop demonstrating polymorphism
    while (running) {
        // POLYMORPHISM IN ACTION!
        // displayMenu() shows different menus based on whether currentUser is Admin or Student
        // Even though currentUser is a User* pointer, the correct derived class method is called
        currentUser->displayMenu();
        cin >> choice;      // Get user's menu choice
        cin.ignore();       // Ignore the newline character left in the input buffer
        
        // DYNAMIC CASTING - Handle menu choices based on actual user type
        // dynamic_cast<Admin*> tries to convert User* to Admin*
        // If currentUser is actually an Admin, it succeeds and returns the pointer
        // If currentUser is not an Admin (it's a Student), it returns nullptr
        if (Admin* admin = dynamic_cast<Admin*>(currentUser)) {
            // This block executes only if the user is an Admin
            // 'admin' is now an Admin* pointer, so we can call Admin-specific methods
            
            switch (choice) {
                case 1:
                    // Call admin-specific method to manage (add/edit/delete) events
                    admin->manageEvents();
                    break;
                case 2:
                    // View all events in the system
                    admin->viewAllEvents();
                    break;
                case 3:
                    // Display statistics (total events, registrations, occupancy)
                    admin->displayEventStats();
                    break;
                case 4:
                    // View who registered for which events
                    admin->viewRegistrationReports();
                    break;
                case 5:
                    // Manage users (add students, view all users)
                    admin->manageUsers();
                    break;
                case 6:
                    // Logout - exit the main loop
                    cout << "\nLogging out..." << endl;
                    cout << "Thank you for using Admin panel!" << endl;
                    running = false;    // This will exit the while loop
                    break;
                default:
                    cout << "Invalid choice! Please select 1-6." << endl;
            }
        } 
        else if (Student* student = dynamic_cast<Student*>(currentUser)) {
            // This block executes only if the user is a Student
            // 'student' is now a Student* pointer, so we can call Student-specific methods
            
            switch (choice) {
                case 1: {
                    // View available events for registration
                    student->viewAvailableEvents();
                    
                    // Ask if they want to register
                    cout << "\nWould you like to register for an event? (yes/no): ";
                    string regChoice;
                    getline(cin, regChoice);    // getline reads the entire line (including spaces)
                    
                    // Convert to lowercase and trim for case-insensitive comparison
                    if (toLower(trim(regChoice)) == "yes") {
                        student->registerForEvent();
                    }
                    break;
                }
                case 2:
                    // View events the student is registered for
                    student->viewMyRegistrations();
                    break;
                case 3: {
                    // Search/Filter events submenu
                    cout << "1. Search by Name" << endl;
                    cout << "2. Filter by Date" << endl;
                    cout << "Choose option: ";
                    int searchChoice;
                    cin >> searchChoice;
                    cin.ignore();    // Clear the newline from input buffer
                    
                    if (searchChoice == 1) {
                        student->searchEventByName();       // Search by partial name match
                    } else if (searchChoice == 2) {
                        student->filterEventsByDate();      // Filter by specific date
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
                    break;
                }
                case 4:
                    // Logout - exit the main loop
                    cout << "\nLogging out..." << endl;
                    cout << "Thank you for using Student portal!" << endl;
                    running = false;    // This will exit the while loop
                    break;
                default:
                    cout << "Invalid choice! Please select 1-4." << endl;
            }
        }
    }
    
    // Cleanup memory to prevent memory leaks
    // We used 'new' to create the user object, so we must use 'delete' to free that memory
    // This is CRITICAL in C++ - forgetting to delete causes memory leaks
    delete currentUser;
    
    cout << "\n=== SESSION ENDED ===" << endl;
    cout << "Thank you for using College Event Management System!" << endl;
    
    return 0;    // Return 0 to indicate successful program execution
}
