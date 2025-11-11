# 📚 C++ Event Management System - Complete Learning Guide

## 🎯 Project Overview

This is a **College Event Management System** built in C++ that demonstrates core Object-Oriented Programming (OOP) concepts. The system allows:
- **Admins** to create, edit, and delete events, and manage users
- **Students** to browse events, register/unregister, and search for events

---

## 🏗️ Project Structure Explained

```
event-management-cpp/
├── headers/           # Header files (.h) - Class declarations
│   ├── user.h        # Base User class
│   ├── admin.h       # Admin class (inherits from User)
│   ├── student.h     # Student class (inherits from User)
│   ├── event.h       # Event class
│   ├── registration.h # Registration class
│   └── utils.h       # Utility functions
│
├── src/              # Source files (.cpp) - Implementation
│   ├── main.cpp      # Entry point - starts the program
│   ├── user.cpp      # User class implementation
│   ├── admin.cpp     # Admin class implementation
│   ├── student.cpp   # Student class implementation
│   ├── event.cpp     # Event class implementation
│   ├── registration.cpp # Registration class implementation
│   └── utils.cpp     # Utility functions implementation
│
├── data/             # Data files - Persistent storage
│   ├── users.txt     # User accounts
│   ├── events.txt    # Event information
│   └── registrations.txt # Student registrations
│
└── build/            # Compiled output
    └── event-management # Executable program
```

---

## 🔑 Key Concepts You'll Learn

### 1. **Header Files vs Implementation Files**

**Header Files (.h)**
- Contain **declarations** (what exists)
- Example: "There's a class called User with these methods"
- Included by other files using `#include "user.h"`
- Protected by include guards (`#ifndef`, `#define`, `#endif`) to prevent multiple inclusions

**Implementation Files (.cpp)**
- Contain **definitions** (how things work)
- Example: The actual code inside each method
- Must include their corresponding header file

**Why separate them?**
- Organization: Keep interface separate from implementation
- Compilation efficiency: Only recompile changed files
- Reusability: Multiple files can include the same header

---

### 2. **Classes and Objects**

**What is a Class?**
A **blueprint** for creating objects. It defines:
- **Member variables** (data/attributes)
- **Member functions** (methods/behavior)

**Example from the project:**
```cpp
// Event class blueprint
class Event {
private:
    string eventName;    // Data
    int capacity;        // Data
public:
    void display();      // Behavior
};

// Creating objects from the class
Event techFest("Tech Fest", 100);  // Object 1
Event musicNight("Music Night", 50); // Object 2
```

---

### 3. **Inheritance (IS-A Relationship)**

**Concept:** A class can inherit properties and methods from another class.

**In this project:**
```
        User (Base Class)
          |
    ______|______
    |           |
  Admin      Student (Derived Classes)
```

- `Admin` **IS-A** `User`
- `Student` **IS-A** `User`
- Both inherit `username`, `password`, `fullName` from User
- Each adds their own specific functionality

**Code Example:**
```cpp
class Admin : public User {  // Admin inherits from User
    // Admin has all User's members PLUS:
    void manageEvents();     // Admin-specific method
};
```

**Why use inheritance?**
- Code reuse (don't repeat username/password logic)
- Logical hierarchy
- Polymorphism (see next section)

---

### 4. **Polymorphism (Many Forms)**

**Concept:** Same interface, different implementations based on object type.

**Two types in this project:**

#### **Compile-time Polymorphism (Function Overloading)**
Not heavily used in this project, but example:
```cpp
void print(int x);      // Function for integers
void print(string x);   // Same name, different parameter type
```

#### **Runtime Polymorphism (Virtual Functions)** ⭐
The main feature! Let's understand with an example:

```cpp
// In User.h (base class)
virtual void displayMenu() = 0;  // Pure virtual function

// In Admin.cpp
void Admin::displayMenu() {
    cout << "1. Manage Events\n";
    cout << "2. View Reports\n";
}

// In Student.cpp
void Student::displayMenu() {
    cout << "1. Browse Events\n";
    cout << "2. My Registrations\n";
}

// In main.cpp
User* currentUser = new Admin(...);  // Base class pointer
currentUser->displayMenu();           // Calls Admin's version!

currentUser = new Student(...);       // Same pointer, different object
currentUser->displayMenu();           // Now calls Student's version!
```

**Why is this powerful?**
- Write code once that works for multiple types
- Add new user types without changing main.cpp
- Flexibility and extensibility

---

### 5. **Encapsulation (Information Hiding)**

**Concept:** Hide internal details, expose only what's necessary.

**Access Modifiers:**
- `private`: Only accessible within the class
- `protected`: Accessible in the class and derived classes
- `public`: Accessible everywhere

**Example from Event class:**
```cpp
class Event {
private:
    int capacity;              // Hidden from outside
    
public:
    int getCapacity() const;   // Controlled access (read-only)
    void setCapacity(int cap); // Controlled modification (with validation)
};
```

**Why use encapsulation?**
- Prevents invalid data (e.g., negative capacity)
- Easy to change internal implementation
- Clear interface for users of the class

---

### 6. **Pointers and Dynamic Memory**

**What is a Pointer?**
A variable that stores a memory address (points to another variable).

```cpp
int x = 10;        // Regular variable
int* ptr = &x;     // Pointer stores address of x
cout << *ptr;      // Dereference: access value at address (prints 10)
```

**Dynamic Memory Allocation:**
```cpp
User* currentUser = new Admin(...);  // Allocate on heap
// Use currentUser...
delete currentUser;                  // MUST free memory when done!
```

**Why use pointers in this project?**
- Polymorphism requires base class pointers
- `authenticateUser()` returns different types (Admin or Student)
- Flexibility in object lifetime

**Critical Rule:** Every `new` must have a corresponding `delete`!

---

### 7. **File I/O (Reading/Writing Files)**

**Input File Stream (Reading):**
```cpp
ifstream file("data/users.txt");      // Open file for reading
string line;
while (getline(file, line)) {         // Read line by line
    // Process line
}
file.close();                         // Always close!
```

**Output File Stream (Writing):**
```cpp
ofstream file("data/events.txt");     // Open file for writing
file << "Tech Fest|15-03-2025|...\n"; // Write data
file.close();
```

**File Formats in this project:**
- `users.txt`: `username,password,fullname,usertype`
- `events.txt`: `eventname|date|venue|capacity|registered`
- `registrations.txt`: `username|eventname|registrationdate`

---

### 8. **Vectors (Dynamic Arrays)**

**What is a Vector?**
A resizable array from the Standard Template Library (STL).

```cpp
vector<Event> events;                 // Create empty vector
events.push_back(Event(...));         // Add element to end
cout << events.size();                // Get number of elements
Event& e = events[0];                 // Access by index
```

**Why use vectors?**
- Don't need to know size in advance
- Automatically manages memory
- Many useful methods (push_back, erase, clear, etc.)

---

## 📂 How Files Connect

### **Dependency Chain:**

```
main.cpp
  ↓ includes
user.h → admin.h → admin.cpp
       → student.h → student.cpp
  ↓ includes
event.h → event.cpp
  ↓ includes
registration.h → registration.cpp
  ↓ includes
utils.h → utils.cpp
```

### **Execution Flow:**

1. **Program starts** → `main.cpp` → `main()` function
2. **Display welcome** → Shows system features
3. **Login loop:**
   - Get username/password
   - Call `authenticateUser()`
   - Read `data/users.txt`
   - Create `Admin` or `Student` object (dynamic allocation)
4. **Main menu loop:**
   - Call `currentUser->displayMenu()` (polymorphism!)
   - Different menu based on user type
   - Process menu choice
5. **Admin actions:**
   - Manage events → Read/Write `data/events.txt`
   - View reports → Read `data/registrations.txt`
   - Manage users → Read/Write `data/users.txt`
6. **Student actions:**
   - Browse events → Read `data/events.txt`
   - Register → Update both `events.txt` and `registrations.txt`
   - Search → Filter events based on criteria
7. **Logout** → Delete user object (free memory) → Exit

---

## 🔍 Function Categories

### **main.cpp Functions**

| Function | Purpose |
|----------|---------|
| `main()` | Entry point, handles login, main loop, cleanup |
| `authenticateUser()` | Reads users.txt, validates credentials, creates User object |
| `displayWelcome()` | Shows welcome banner |

### **Admin Class Functions**

| Function | Purpose |
|----------|---------|
| `displayMenu()` | Shows admin menu |
| `manageEvents()` | Submenu for CRUD operations on events |
| `addNewEvent()` | Create a new event with validation |
| `editEvent()` | Modify existing event details |
| `deleteEvent()` | Remove an event and its registrations |
| `viewAllEvents()` | Display all events in table format |
| `displayEventStats()` | Show occupancy statistics |
| `viewRegistrationReports()` | See who registered for which events |
| `manageUsers()` | Add students, view all users |
| `loadEventsFromFile()` | Read events.txt into vector |
| `saveEventsToFile()` | Write vector to events.txt |
| `loadRegistrationsFromFile()` | Read registrations.txt into vector |
| `saveRegistrationsToFile()` | Write vector to registrations.txt |

### **Student Class Functions**

| Function | Purpose |
|----------|---------|
| `displayMenu()` | Shows student menu |
| `viewAvailableEvents()` | Display all events with available seats |
| `viewMyRegistrations()` | Show events this student registered for |
| `registerForEvent()` | Sign up for an event (with validation) |
| `unregisterFromEvent()` | Cancel registration |
| `searchEventByName()` | Find events by partial name match |
| `filterEventsByDate()` | Show events on a specific date |
| `getCurrentDateTime()` | Get formatted current timestamp |
| `loadEventsFromFile()` | Read events.txt into vector |
| `saveEventsToFile()` | Write vector to events.txt |
| `loadRegistrationsFromFile()` | Read registrations.txt into vector |
| `saveRegistrationsToFile()` | Write vector to registrations.txt |

### **Event Class Functions**

| Function | Purpose |
|----------|---------|
| Constructor `Event()` | Initialize event object |
| Getters (`getEventName()`, etc.) | Read-only access to private data |
| Setters (`setEventName()`, etc.) | Controlled modification of data |
| `hasAvailableSeats()` | Check if event has room |
| `registerStudent()` | Increment registered count |
| `unregisterStudent()` | Decrement registered count |
| `toFileFormat()` | Convert object to pipe-delimited string |
| `display()` | Show event in table row format |
| `displayDetailed()` | Show complete event information |

### **Registration Class Functions**

| Function | Purpose |
|----------|---------|
| Constructor `Registration()` | Initialize registration object |
| Getters | Access private member variables |
| `toFileFormat()` | Convert object to pipe-delimited string |
| `display()` | Show registration information |

### **Utility Functions**

| Function | Purpose |
|----------|---------|
| `split()` | Split string by delimiter into vector |
| `trim()` | Remove leading/trailing whitespace |
| `isNumeric()` | Check if string contains only digits |
| `isValidDate()` | Validate date format (DD-MM-YYYY) |
| `toLower()` | Convert string to lowercase |

---

## 💡 Common Patterns You'll See

### **1. Load-Modify-Save Pattern**
```cpp
// Used throughout for data persistence
vector<Event> events = loadEventsFromFile();  // 1. Load
events.push_back(newEvent);                   // 2. Modify
saveEventsToFile(events);                     // 3. Save
```

### **2. Input Validation Pattern**
```cpp
// Get input
getline(cin, input);
input = trim(input);

// Validate
if (input.empty()) {
    cout << "Error message";
    return;  // Exit early if invalid
}

// Process valid input
// ...
```

### **3. Search/Filter Pattern**
```cpp
vector<Event> results;  // Results container
for (const auto& item : collection) {
    if (/* condition */) {
        results.push_back(item);  // Add matching items
    }
}
```

### **4. Member Initializer List Pattern**
```cpp
// Constructor with initialization list (more efficient)
Event::Event(string name, int cap) 
    : eventName(name), capacity(cap) {}

// Equivalent to (but better than):
Event::Event(string name, int cap) {
    eventName = name;
    capacity = cap;
}
```

---

## 🎓 Important C++ Concepts Explained

### **const Keyword**
```cpp
// After function parameters: parameter won't be modified
void setName(const string& name);

// After function declaration: function won't modify member variables
string getName() const;

// Variable declaration: value can't be changed
const int MAX_ATTEMPTS = 3;
```

### **Reference (&) vs Pointer (*)**
```cpp
// Reference: Alias to existing variable
void modify(string& str) { str = "new"; }  // Changes original

// Pointer: Stores memory address
void modify(string* str) { *str = "new"; } // Changes original
```

### **auto Keyword**
```cpp
// Compiler automatically determines type
auto x = 5;                    // int
auto name = "John";            // const char*
auto events = loadEvents();    // vector<Event>
```

### **Range-based for Loop**
```cpp
// Modern C++ loop (C++11)
for (const auto& event : events) {
    event.display();
}

// Equivalent to:
for (size_t i = 0; i < events.size(); i++) {
    events[i].display();
}
```

### **Lambda Functions**
```cpp
// Anonymous function (used in find_if)
auto it = find_if(registrations.begin(), registrations.end(),
    [this, &eventName](const Registration& r) {
        return r.getEventName() == eventName;
    });

// [capture](parameters) { body }
```

---

## 🐛 Common Issues and Solutions

### **Issue: Segmentation Fault**
**Cause:** Accessing invalid memory (null pointer, out of bounds)
**Solution:** Check pointers before use, validate array indices

### **Issue: Memory Leak**
**Cause:** Using `new` without `delete`
**Solution:** Always pair `new` with `delete`

### **Issue: File Not Opening**
**Cause:** Wrong path, file doesn't exist, no permissions
**Solution:** Check `if (!file.is_open())`, verify file path

### **Issue: Leftover Input in Buffer**
**Cause:** Mixing `cin >>` and `getline()`
**Solution:** Use `cin.ignore()` after `cin >>`

---

## 🎯 Learning Path

### **Beginner Level**
1. Start with `event.cpp` - Simple class with no inheritance
2. Read `registration.cpp` - Another simple class
3. Study `utils.cpp` - Standalone functions

### **Intermediate Level**
4. Understand `user.cpp` - Base class with virtual functions
5. Read `main.cpp` - See how everything connects
6. Study polymorphism in action

### **Advanced Level**
7. Deep dive into `admin.cpp` - Complex file I/O and vector manipulation
8. Analyze `student.cpp` - Search algorithms and lambda functions
9. Understand the complete data flow

---

## 📝 Quick Reference

### **Compilation Command**
```bash
make              # Compile the project
./build/event-management  # Run the program
```

### **Default Login Credentials**
- **Admin:** `admin` / `admin123`
- **Students:**
  - `john` / `pass123`
  - `alice` / `alice456`
  - `bob` / `bob789`

### **File Locations**
- Source code: `/workspaces/event-management-cpp/src/`
- Headers: `/workspaces/event-management-cpp/headers/`
- Data files: `/workspaces/event-management-cpp/data/`

---

## 🚀 Next Steps

1. **Read the code comments** - Every function is explained
2. **Experiment** - Modify small parts and see what happens
3. **Add features** - Try implementing:
   - Password validation (minimum length, special characters)
   - Event categories (Sports, Cultural, Technical)
   - Export reports to CSV
   - Email notifications (simulated)
4. **Optimize** - Look for repeated code that could be functions
5. **Debug** - Use `cout` statements to understand program flow

---

## 💬 Questions You Might Have

**Q: Why use classes instead of just functions?**
A: Classes bundle related data and functions together, making code more organized and maintainable.

**Q: When should I use inheritance?**
A: When you have an "IS-A" relationship and want to share common functionality.

**Q: What's the difference between stack and heap memory?**
A: Stack = automatic (local variables), Heap = manual (new/delete, dynamic allocation).

**Q: Why are some functions const?**
A: To indicate they don't modify the object, enabling better optimization and preventing bugs.

**Q: What's a pure virtual function?**
A: A virtual function with `= 0` that must be implemented by derived classes (makes class abstract).

---

## 📖 Additional Resources

- **C++ Documentation:** https://cppreference.com
- **OOP Concepts:** Look for "Four Pillars of OOP"
- **STL (Vectors, Algorithms):** https://cplusplus.com/reference/stl/
- **Memory Management:** Research RAII (Resource Acquisition Is Initialization)

---

**Happy Learning! 🎉**

Remember: The best way to learn is by doing. Read the code, run it, break it, fix it, and experiment!
