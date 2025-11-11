#include "utils.h"

// ========================================
// UTILS.CPP - Utility Functions Implementation
// ========================================
// This file contains helper functions used throughout the application.
// These are standalone functions (not part of any class) that perform common tasks.

// Split string by delimiter
// What it does: Breaks a string into parts based on a separator character
// Example: "apple,banana,orange" with delimiter ',' → ["apple", "banana", "orange"]
// Used for: Parsing data from text files (like users.txt, events.txt)
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;         // Vector to store the split parts
    stringstream ss(str);          // Create a string stream from the input string
    string token;                  // Temporary variable to hold each part
    
    // getline with delimiter reads until it finds the delimiter character
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);   // Add each part to the vector
    }
    
    return tokens;                 // Return the vector containing all parts
}

// Trim whitespace from string
// What it does: Removes spaces, tabs, and newlines from the beginning and end of a string
// Example: "  hello world  " → "hello world"
// Why needed: File data often has unwanted spaces that need to be removed
string trim(const string& str) {
    // Find the first character that is NOT whitespace
    size_t first = str.find_first_not_of(" \t\n\r");
    
    // If the entire string is whitespace, return empty string
    if (first == string::npos) return "";
    
    // Find the last character that is NOT whitespace
    size_t last = str.find_last_not_of(" \t\n\r");
    
    // Extract the substring from first non-space to last non-space character
    return str.substr(first, last - first + 1);
}

// Check if string contains only digits
// What it does: Validates if a string contains only numbers (0-9)
// Example: "123" → true, "12a3" → false
// Used for: Validating numeric input and date components
bool isNumeric(const string& str) {
    if (str.empty()) return false;     // Empty string is not numeric
    
    // Check each character in the string
    for (char c : str) {
        if (!isdigit(c)) return false; // If any character is not a digit, return false
    }
    
    return true;                       // All characters are digits
}

// Validate date format (DD-MM-YYYY)
// What it does: Checks if a date string follows the correct format and has valid values
// Example: "15-03-2025" → true, "32-13-2020" → false
// Why needed: Ensures users enter dates in the correct format when creating/editing events
bool isValidDate(const string& date) {
    // Check if length is exactly 10 characters (DD-MM-YYYY)
    if (date.length() != 10) return false;
    
    // Check if hyphens are in the correct positions
    if (date[2] != '-' || date[5] != '-') return false;
    
    // Extract day, month, and year as substrings
    string day = date.substr(0, 2);      // Characters 0-1
    string month = date.substr(3, 2);    // Characters 3-4
    string year = date.substr(6, 4);     // Characters 6-9
    
    // Check if all components are numeric
    if (!isNumeric(day) || !isNumeric(month) || !isNumeric(year)) return false;
    
    // Convert strings to integers for range validation
    int d = stoi(day);       // stoi = "string to integer"
    int m = stoi(month);
    int y = stoi(year);
    
    // Validate month range (1-12)
    if (m < 1 || m > 12) return false;
    
    // Validate day range (1-31) - simplified, doesn't check month-specific days
    if (d < 1 || d > 31) return false;
    
    // Validate year (must be 2025 or later)
    if (y < 2025) return false;
    
    return true;    // All validations passed
}

// Convert string to lowercase
// What it does: Converts all uppercase letters in a string to lowercase
// Example: "Hello World" → "hello world"
// Used for: Case-insensitive comparisons (like searching for event names)
string toLower(const string& str) {
    string result = str;    // Create a copy of the input string
    
    // transform applies the ::tolower function to each character
    // ::tolower is a standard library function that converts a character to lowercase
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    
    return result;          // Return the lowercase version
}
