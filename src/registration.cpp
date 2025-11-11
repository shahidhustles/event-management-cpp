#include "registration.h"

// ========================================
// REGISTRATION.CPP - Registration Class Implementation
// ========================================
// This file implements the Registration class which represents a student's registration for an event.
// Each Registration object links a student to an event with a timestamp.

// Constructor with member initializer list
// What it does: Creates a Registration object linking a student to an event
// Parameters: username (student's username), event (event name), regDate (registration timestamp)
// The colon syntax (:) is called a "member initializer list" - it's more efficient than assigning in the body
Registration::Registration(string username, string event, string regDate)
    : studentUsername(username),      // Initialize studentUsername member
      eventName(event),                // Initialize eventName member
      registrationDate(regDate) {}     // Initialize registrationDate member

// Getter methods - Allow read-only access to private member variables
// 'const' at the end means these functions don't modify the object
string Registration::getStudentUsername() const { 
    return studentUsername;    // Return which student registered
}

string Registration::getEventName() const { 
    return eventName;          // Return which event they registered for
}

string Registration::getRegistrationDate() const { 
    return registrationDate;   // Return when they registered
}

// Format registration data for file storage
// What it does: Converts the registration object into a string for saving to registrations.txt
// Format: username|eventname|date
// Example: "john|Tech Fest 2025|15-03-2025 14:30"
// Why pipe (|): We use | as a separator because event names might contain commas
string Registration::toFileFormat() const {
    return studentUsername + "|" + eventName + "|" + registrationDate;
}

// Display registration info to console
// What it does: Prints the registration details in a readable format
// Used by: Admin when viewing registration reports
void Registration::display() const {
    cout << "  " << studentUsername << " -> " << eventName 
         << " (Registered: " << registrationDate << ")" << endl;
}
