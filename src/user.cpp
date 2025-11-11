#include "user.h"

// ========================================
// USER.CPP - Base User Class Implementation
// ========================================
// This file implements the User class, which serves as the base class for both Admin and Student.
// It demonstrates inheritance and polymorphism - two core OOP concepts.

// Constructor to initialize user data
// What it does: When you create a User object, this sets up the username, password, and full name
// Parameters: uname (username), pass (password), name (full name of user)
User::User(string uname, string pass, string name) {
    username = uname;      // Store username in the member variable
    password = pass;       // Store password in the member variable
    fullName = name;       // Store full name in the member variable
}

// Getter methods - These allow other parts of the program to read private member variables
// 'const' at the end means this function won't modify any member variables (read-only)
string User::getUsername() const { 
    return username;       // Return the username
}

string User::getFullName() const { 
    return fullName;       // Return the full name
}

// Authentication method
// What it does: Checks if the provided password matches the stored password
// Returns: true if passwords match, false otherwise
bool User::authenticate(string pass) {
    return password == pass;   // Compare the provided password with stored password
}

// Virtual destructor for proper cleanup
// What it does: This ensures that when a derived class (Admin/Student) object is deleted,
// their destructors are called properly. The 'virtual' keyword is important for polymorphism.
// Why needed: Prevents memory leaks when using base class pointers to derived objects
User::~User() {
    // Empty destructor - no dynamic memory to clean up in this class
}
