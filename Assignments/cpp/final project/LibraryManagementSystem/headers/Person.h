#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

namespace LibrarySystem {
class Person {
protected:
    int id;
    string name;
    string phone;
public:
    Person();
    Person(int id, string name, string phone);
    virtual void displayInfo() const = 0;
    virtual ~Person();
    int getId() const;
    string getName() const;
};
}
#endif
