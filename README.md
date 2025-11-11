# 📅 Event Management System - C++

A comprehensive event management system demonstrating Object-Oriented Programming (OOP) principles in C++. This application allows administrators to manage events and students to register for events.

> **📖 NEW LEARNERS:** Check out [LEARNING_GUIDE.md](LEARNING_GUIDE.md) for a complete walkthrough of the code with detailed explanations!

---

## 🏗️ Project Structure

```
event-management-cpp/
├── headers/              # Class declarations (.h files)
│   ├── user.h           # Base User class
│   ├── admin.h          # Admin class (inherits User)
│   ├── student.h        # Student class (inherits User)
│   ├── event.h          # Event class
│   ├── registration.h   # Registration class
│   └── utils.h          # Utility functions
│
├── src/                 # Implementation (.cpp files)
│   ├── main.cpp         # Program entry point ⭐
│   ├── user.cpp         # User implementation
│   ├── admin.cpp        # Admin implementation
│   ├── student.cpp      # Student implementation
│   ├── event.cpp        # Event implementation
│   ├── registration.cpp # Registration implementation
│   └── utils.cpp        # Utility functions
│
├── data/                # Data persistence
│   ├── users.txt        # User accounts
│   ├── events.txt       # Event information
│   └── registrations.txt # Student registrations
│
├── build/               # Compiled executable
│   └── event-management
│
├── Makefile            # Build configuration
├── README.md           # This file
└── LEARNING_GUIDE.md   # Detailed learning resource 📖
```

---

## 📋 File Format Specifications

### events.txt (Pipe-delimited)
```
EventName|DD-MM-YYYY|Venue|Capacity|RegisteredCount
Tech Fest 2025|15-03-2025|Main Auditorium|200|45
```

### registrations.txt (Pipe-delimited)
```
StudentUsername|EventName|DD-MM-YYYY HH:MM
john|Tech Fest 2025|11-11-2025 14:30
```

### users.txt (Comma-separated)
```
username,password,fullname,usertype
admin,admin123,System Administrator,admin
john,pass123,John Smith,student
```

---

## ✨ Features

### 🔐 Authentication & Authorization
- Secure login system with attempt limits
- Role-based access control (Admin/Student)
- User profile management

### 👨‍💼 Admin Features
- **Event Management (CRUD)**
  - ➕ Create new events with validation
  - ✏️ Edit existing events (name, date, venue, capacity)
  - 🗑️ Delete events (with cascading registration removal)
- **Reports & Statistics**
  - 📊 Event occupancy statistics
  - 📝 Registration reports by event
  - 👥 View all system users
- **User Management**
  - ➕ Add new student accounts
  - 👀 View all registered users

### 🎓 Student Features
- **Event Browsing**
  - 📅 View all available events
  - 🔍 Search events by name (partial match)
  - 📆 Filter events by date
- **Registration Management**
  - ✅ Register for events (with capacity checking)
  - ❌ Unregister from events
  - 📋 View personal registrations
- **Smart Validations**
  - Duplicate registration prevention
  - Capacity limit enforcement
  - Real-time availability display

---

## 🎯 OOP Concepts Demonstrated

| Concept | Implementation |
|---------|---------------|
| **Inheritance** | `Admin` and `Student` inherit from `User` base class |
| **Polymorphism** | Virtual functions (`displayMenu()`, `getUserType()`) |
| **Encapsulation** | Private members with public getters/setters |
| **Abstraction** | Pure virtual functions in `User` class |
| **Dynamic Binding** | Using base class pointers for derived objects |
| **File I/O** | Persistent data storage in text files |
| **STL Usage** | Vectors, algorithms (find_if), string operations |

---

## 🚀 Quick Start

### Compilation
```bash
make              # Compile the project
make clean        # Remove compiled files
```

### Running the Program
```bash
./build/event-management
```

### Default Login Credentials

**Admin Account:**
- Username: `admin`
- Password: `admin123`

**Student Accounts:**
- `john` / `pass123`
- `alice` / `alice456`
- `bob` / `bob789`

---

## 📖 How to Learn from This Project

### For Beginners (Know basic C++)
1. **Start here:** Read [LEARNING_GUIDE.md](LEARNING_GUIDE.md) sections 1-3
2. **Read these files in order:**
   - `headers/event.h` → `src/event.cpp` (simple class)
   - `headers/user.h` → `src/user.cpp` (base class)
   - `src/main.cpp` (see how it all connects)

### For Intermediate (Know OOP basics)
1. **Focus on:** Polymorphism implementation
2. **Study these files:**
   - `src/main.cpp` - Dynamic casting and polymorphism
   - `src/admin.cpp` - File I/O and vector manipulation
   - `src/student.cpp` - Search algorithms and lambda functions

### For Advanced (Want to go deeper)
1. **Analyze:** Memory management and design patterns
2. **Explore:** Load-Modify-Save pattern throughout the codebase
3. **Try:** Add new features (see suggestions below)

---

## 🔍 Code Navigation Tips

### Understanding a Function
1. **Look at the header comment** - Explains what it does
2. **Check inline comments** - Explain how it works
3. **Refer to LEARNING_GUIDE.md** - Understand the concepts

### Finding Things
- **Class declarations:** Check `headers/` folder
- **Class implementations:** Check `src/` folder  
- **Function purpose:** Read the comment block above it
- **How classes connect:** See "How Files Connect" in LEARNING_GUIDE.md

---

## 💻 System Requirements

- **Compiler:** g++ with C++11 support or later
- **OS:** Linux, macOS, or Windows (with MinGW/WSL)
- **Make:** GNU Make for building

---

## 🎨 Sample Output

```
=================================================
   COLLEGE EVENT MANAGEMENT SYSTEM - PHASE 2    
=================================================

=== LOGIN SYSTEM ===
Username: john
Password: pass123

*** LOGIN SUCCESSFUL ***
User Type: Student
Welcome, John Smith!

=== STUDENT DASHBOARD ===
1. Browse Available Events
2. My Registrations
3. Search Events
4. Logout
Choose an option:
```

---

## 📝 Key Functions by File

### main.cpp
- `main()` - Program entry point and main loop
- `authenticateUser()` - Login validation and user object creation
- `displayWelcome()` - Welcome banner

### admin.cpp
- `manageEvents()` - CRUD operations menu
- `addNewEvent()` / `editEvent()` / `deleteEvent()` - Event management
- `viewRegistrationReports()` - See registration data
- `displayEventStats()` - Show statistics

### student.cpp
- `registerForEvent()` - Sign up for an event
- `unregisterFromEvent()` - Cancel registration
- `searchEventByName()` - Find events by partial name
- `viewMyRegistrations()` - Show user's registrations

### event.cpp
- Getters/Setters for event properties
- `hasAvailableSeats()` - Check capacity
- `display()` - Table format display
- `toFileFormat()` - Convert to saveable string

### utils.cpp
- `split()` - Parse file data
- `trim()` - Clean whitespace
- `isValidDate()` - Date validation
- `toLower()` - Case-insensitive comparisons

---

## 🐛 Common Issues

### "Could not open file"
- **Cause:** Data files missing or wrong path
- **Fix:** Ensure `data/` folder exists with required .txt files

### Segmentation Fault
- **Cause:** Null pointer access or out-of-bounds
- **Fix:** Check pointer validity before use

### Input Not Working
- **Cause:** Buffer not cleared after `cin >>`
- **Fix:** Use `cin.ignore()` after reading with `cin >>`

---

## 🎓 Learning Resources

- **LEARNING_GUIDE.md** - Complete walkthrough with concepts
- **Code Comments** - Detailed explanations in every file
- **C++ Reference** - https://cppreference.com
- **STL Documentation** - https://cplusplus.com/reference/stl/

---

## 🚧 Future Enhancement Ideas

- [ ] Password encryption (hashing)
- [ ] Event categories (Sports, Cultural, Technical)
- [ ] Waitlist for full events
- [ ] Export reports to CSV
- [ ] Email notifications (simulated)
- [ ] Event cancellation with refunds
- [ ] Multi-day events
- [ ] Event capacity tracking by date/time
- [ ] Admin approval for registrations
- [ ] Student profile management

---

## 📊 Project Statistics

- **Lines of Code:** ~2000+
- **Classes:** 5 (User, Admin, Student, Event, Registration)
- **Files:** 15 (headers + implementations)
- **Features:** 20+ distinct operations
- **OOP Concepts:** All 4 pillars demonstrated

---

## 🤝 Contributing

This is a learning project. Feel free to:
1. Fork the repository
2. Add new features
3. Improve documentation
4. Share your enhancements

---

## 📄 License

This project is for educational purposes.

---

## 🙋 Need Help?

1. **Read LEARNING_GUIDE.md** - Most questions answered there
2. **Check code comments** - Detailed explanations inline
3. **Experiment** - Change things and see what happens
4. **Debug** - Use `cout` to track program flow

---

**Happy Coding! 🎉**

*Remember: The best way to learn programming is by reading code, understanding it, and then modifying it!*

#### CRUD Operations for Events
- **Create**: Add new events with validation
- **Read**: View all events or search/filter
- **Update**: Edit event details (date, venue, capacity)
- **Delete**: Remove events and associated registrations

#### Event Management
- Add new events with automatic duplicate prevention
- Edit event properties (name, date, venue, capacity)
- Delete events with cascade delete for registrations
- Capacity validation to prevent double-booking
- Real-time registration count updates

#### Registration System
- Students can register for available events
- Automatic duplicate registration prevention
- Seat availability checking
- Student unregistration with automatic count decrement
- Registration timestamp tracking

#### Student Features
- **Browse Events**: View all available events with availability
- **My Registrations**: View personal registered events
- **Event Search**: 
  - Search by event name (case-insensitive)
  - Filter events by date
- **Register/Unregister**: Easy registration management
- **Event Details**: View detailed event information

#### Admin Features
- **Event Management Menu**: Create, edit, delete events
- **Event Statistics**: View system-wide statistics
  - Total events, capacity, registrations
  - Per-event occupancy percentages
- **Registration Reports**:
  - View all participants for specific events
  - Registration summary across all events
  - Participant lists with registration dates
- **User Management**:
  - Add new student accounts
  - View all system users
  - Automatic username duplication prevention

#### Data Validation
- Date format validation (DD-MM-YYYY)
- Positive capacity checking
- Non-empty string validation
- Username/Event name uniqueness checking
- Duplicate registration prevention
- Capacity constraints enforcement

#### Error Handling
- File operation error handling
- Input validation with user feedback
- Graceful error recovery
- Informative error messages

---

## OOP Concepts Demonstrated

### 1. **Inheritance**
- `User` base class with `Admin` and `Student` derived classes
- Shared functionality in base class
- Specialized behavior in derived classes

### 2. **Polymorphism**
- Virtual functions: `displayMenu()`, `getUserType()`
- Dynamic casting for user-type specific operations
- Function overriding in derived classes

### 3. **Encapsulation**
- Protected class members
- Public getter methods
- Private data in classes

### 4. **Abstraction**
- Pure virtual functions in base class
- Complex operations hidden from user
- Simple user interfaces for complex functionality

### 5. **Additional Patterns**
- `Event` and `Registration` classes for data management
- Utility functions for string operations
- Vector containers for dynamic data storage

---

## Compilation and Execution

### Compile
```bash
g++ -std=c++17 -o event-management event-management.cpp
```

### Run
```bash
./event-management
```

### Default Test Credentials
```
Admin:
  Username: admin
  Password: admin123

Students:
  Username: john     | Password: pass123
  Username: alice    | Password: alice456
  Username: bob      | Password: bob789
```

---

## Usage Guide

### Admin Menu
1. **Manage Events** - Create, edit, or delete events
2. **View All Events** - See complete event list with details
3. **View Event Statistics** - System-wide statistics and occupancy
4. **View Registration Reports** - Participant lists and registrations
5. **Manage Users** - Add new students or view all users
6. **Logout** - Exit the system

### Student Menu
1. **Browse Available Events** - View all events and optionally register
2. **My Registrations** - View, see details, or unregister from events
3. **Search Events** - Search by name or filter by date
4. **Logout** - Exit the system

---

## Code Architecture

### Main Components

#### Utility Functions
- `split()` - String parsing by delimiter
- `trim()` - Whitespace removal
- `isNumeric()` - Numeric validation
- `isValidDate()` - Date format validation
- `toLower()` - String case conversion

#### Event Class
- Stores event details and registration info
- Methods for availability checking
- File format conversion
- Display methods with formatting

#### Registration Class
- Tracks student-event registrations
- Stores registration timestamps
- File format conversion

#### User Hierarchy
- `User` - Abstract base class
- `Admin` - Event and user management
- `Student` - Event browsing and registration

#### Core Functions
- `authenticateUser()` - Login processing
- `main()` - Application flow control

---

## Key Implementation Details

### File I/O Strategy
- Load entire files into memory (vectors)
- Modify in-memory structures
- Write complete files back to disk
- Atomic operations (prevent partial writes)

### Date-Time Handling
- Date format: DD-MM-YYYY
- Registration timestamp: DD-MM-YYYY HH:MM
- Current system time for registration dates

### Validation Rules
1. **Event Names**: Non-empty, unique (case-insensitive)
2. **Dates**: DD-MM-YYYY format, year >= 2025
3. **Capacity**: Positive integer
4. **Username**: Unique, non-empty
5. **Registrations**: One per student per event, respects capacity

### Memory Management
- Dynamic allocation for User objects
- Proper cleanup with delete statements
- No memory leaks in normal operation

---

## Future Enhancements (Phase 3)

- Header file separation (.h and .cpp files)
- Database integration (SQLite/MySQL)
- Event categories/tags
- Rating and review system
- Email notifications
- Seat preference selection
- Event cancellation with notification
- Admin approval workflow
- Dashboard analytics
- CSV export functionality

---

## Technical Specifications

- **Language**: C++17
- **Compilation**: g++ with C++17 standard
- **Standard Library**: iostream, fstream, string, vector, algorithm, sstream, iomanip, ctime
- **File Format**: Plain text (pipe and comma-delimited)
- **Data Persistence**: Text-based file storage
- **User Interface**: Terminal/Console

---

## Testing Checklist

- ✅ Admin can create events
- ✅ Admin can edit event details
- ✅ Admin can delete events
- ✅ Student can register for events
- ✅ Student can unregister from events
- ✅ Capacity constraints are enforced
- ✅ Duplicate registrations are prevented
- ✅ Search and filter functionality works
- ✅ Registration reports generate correctly
- ✅ New user creation works
- ✅ Data persists across sessions
- ✅ Error handling is comprehensive

---

## Notes

- All data is stored in plain text files in the same directory as the executable
- Registration timestamps are automatically generated
- The system supports unlimited events and users
- Capacity can be changed if current registrations allow it
- Deleting an event removes all associated registrations

---

**Version**: 2.0 (Phase 2 Complete)  
**Last Updated**: November 11, 2025  
**Status**: Ready for Production
