#include "../headers/Librarian.h"
using namespace LibrarySystem;

Librarian::Librarian() : Person() {
    employeeId = 0;
    salary = 0;
}

Librarian::Librarian(int id, string name, string phone, int employeeId, double salary)
    : Person(id, name, phone) {
    this->employeeId = employeeId;
    this->salary = salary;
}

void Librarian::displayInfo() const {
    cout << "Librarian ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Salary: " << salary << endl;
}
