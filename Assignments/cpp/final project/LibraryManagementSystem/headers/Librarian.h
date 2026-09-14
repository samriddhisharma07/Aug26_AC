#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Person.h"

namespace LibrarySystem {
class Librarian : public Person {
    int employeeId;
    double salary;
public:
    Librarian();
    Librarian(int id, string name, string phone, int employeeId, double salary);
    void displayInfo() const override;
};
}
#endif
