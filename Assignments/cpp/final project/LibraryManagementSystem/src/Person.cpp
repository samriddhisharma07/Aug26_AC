#include "../headers/Person.h"
using namespace LibrarySystem;

Person::Person() {
    id = 0;
    name = "";
    phone = "";
}

Person::Person(int id, string name, string phone) {
    this->id = id;
    this->name = name;
    this->phone = phone;
}

Person::~Person() {}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}
