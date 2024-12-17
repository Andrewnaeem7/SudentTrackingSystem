#include <iostream>
#include <string>
#include "StudentManger.h"
using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls"); // Clear console on Windows
#else
    system("clear"); // Clear console on Linux/macOS
#endif
}

void displayMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student to Front\n";
    cout << "2. Add Student to Back\n";
    cout << "3. Delete Student from Front\n";
    cout << "4. Delete Student from Back\n";
    cout << "5. Delete Student by ID\n";
    cout << "6. Display All Students\n";
    cout << "7. Search Student by ID\n";
    cout << "8. Number of Students\n";
    cout << "9. Save Students to File\n";
    cout << "10. Exit\n";
    cout << "11. Clear console\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    StudentManger manager;
    int choice, id, numSubjects;
    string name;
    vector<float> grades;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add a new student to the front of the list
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            grades.clear();
            cout << "Enter the number of subjects: ";
            cin >> numSubjects;

            for (int i = 0; i < numSubjects; ++i) {
                float grade;
                cout << "Enter grade for subject " << i + 1 << ": ";
                cin >> grade;
                grades.push_back(grade); 
            }

            manager.addStudentFront(Student(id, name, grades));
            cout << "Student added to front.\n";
            break;
        }
        case 2: {
            // Add a new student to the back of the list
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            grades.clear(); 
            cout << "Enter the number of subjects: ";
            cin >> numSubjects;

            for (int i = 0; i < numSubjects; ++i) {
                float grade;
                cout << "Enter grade for subject " << i + 1 << ": ";
                cin >> grade;
                grades.push_back(grade); 
            }

            manager.addStudentBack(Student(id, name, grades));
            cout << "Student added to back.\n";
            break;
        }
        case 3:
            // Delete the student at the front of the list
            manager.deleteStudentFront();
            cout << "Student deleted from front.\n";
            break;
        case 4:
            // Delete the student at the back of the list
            manager.deleteStudentBack();
            cout << "Student deleted from back.\n";
            break;
        case 5:
            // Delete a student by their ID
            cout << "Enter Student ID to delete: ";
            cin >> id;
            manager.deleteStudentWithId(id);
            break;
        case 6:
            // Display all students
            manager.displayAllStudent();
            break;
        case 7:
            // Search for a student by their ID
            cout << "Enter Student ID to search: ";
            cin >> id;
            try {
                Student found = manager.getStudent(id);
                found.display();
            }
            catch (...) {
                cout << "Student not found.\n";
            }
            break;
        case 8:
            // Display the total number of students
            cout << "Number of students: " << manager.numberOfStudentds() << "\n";
            break;
        case 9:
            // Save students to a file
            cout << "Saving students to file...\n";
            manager.saveAllStudents(); 
            break;
        case 10:
            // Exit the program
            cout << "Exiting...\n";
            return 0;
        case 11:
            clearConsole();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
