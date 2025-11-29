#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Student {
    int student_id;
    string name;
    int roll_no;
    string student_class;
    float marks;
    string address;

public:
    void input() {
        cout << "Enter Student ID: ";
        cin >> student_id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll_no;
        cin.ignore();
        cout << "Enter Class: ";
        getline(cin, student_class);
        cout << "Enter Marks: ";
        cin >> marks;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void display() {
        cout << "Student ID: " << student_id << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Class: " << student_class << endl;
        cout << "Marks: " << marks << endl;
        cout << "Address: " << address << endl;
        cout << "--------------------------------------" << endl;
    }

    int getID() {
        return student_id;
    }

    void writeToFile(ofstream &file) {
        file << student_id << "|"
             << name << "|"
             << roll_no << "|"
             << student_class << "|"
             << marks << "|"
             << address << endl;
    }

    bool readFromLine(string &line) {
        stringstream ss(line);
        string part;
        getline(ss, part, '|');
        student_id = stoi(part);
        getline(ss, name, '|');
        getline(ss, part, '|');
        roll_no = stoi(part);
        getline(ss, student_class, '|');
        getline(ss, part, '|');
        marks = stof(part);
        getline(ss, address);
        return true;
    }
};

void addRecord() {
    ofstream file("students.txt", ios::app);
    Student s;
    cout << "\nEnter Student Details:\n";
    s.input();
    s.writeToFile(file);
    file.close();
    cout << "Record Added Successfully!\n";
}

void displayRecords() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No database found.\n";
        return;
    }

    string line;
    Student s;
    cout << "\n--- Student Database ---\n";
    while (getline(file, line)) {
        if (s.readFromLine(line))
            s.display();
    }
    file.close();
}

void searchRecord() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No database found.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    string line;
    Student s;
    bool found = false;

    while (getline(file, line)) {
        if (s.readFromLine(line) && s.getID() == id) {
            cout << "\nRecord Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record Not Found.\n";

    file.close();
}

void deleteRecord() {
    ifstream fin("students.txt");
    if (!fin) {
        cout << "No database found.\n";
        return;
    }

    ofstream fout("temp.txt");
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    string line;
    Student s;
    bool found = false;

    while (getline(fin, line)) {
        if (s.readFromLine(line)) {
            if (s.getID() != id)
                fout << line << endl;
            else
                found = true;
        }
    }

    fin.close();
    fout.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Record Deleted Successfully!\n";
    else
        cout << "Record Not Found.\n";
}

void updateRecord() {
    ifstream fin("students.txt");
    if (!fin) {
        cout << "No database found.\n";
        return;
    }

    ofstream fout("temp.txt");
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    string line;
    Student s;
    bool found = false;

    while (getline(fin, line)) {
        if (s.readFromLine(line)) {
            if (s.getID() == id) {
                cout << "\nEnter new details:\n";
                s.input();
                found = true;
            }
            s.writeToFile(fout);
        }
    }

    fin.close();
    fout.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Record Updated Successfully!\n";
    else
        cout << "Record Not Found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== Student Database Menu ======\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: cout << "Exiting Program...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 6);

    return 0;
}
