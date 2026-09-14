#include "../headers/Member.h"
using namespace LibrarySystem;

Member::Member() : Person() {
    bookCount = 0;
    books = new int[5];
}

Member::Member(int id, string name, string phone) : Person(id, name, phone) {
    bookCount = 0;
    books = new int[5];
}

Member::Member(const Member &m) : Person(m.id, m.name, m.phone) {
    bookCount = m.bookCount;
    books = new int[5];
    for (int i = 0; i < bookCount; i++)
        books[i] = m.books[i];
}

Member& Member::operator=(const Member &m) {
    if (this != &m) {
        id = m.id;
        name = m.name;
        phone = m.phone;
        bookCount = m.bookCount;
        for (int i = 0; i < bookCount; i++)
            books[i] = m.books[i];
    }
    return *this;
}

bool Member::operator==(const Member &m) const {
    return id == m.id;
}

Member::~Member() {
    delete[] books;
}

void Member::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Issued Books: " << bookCount << endl;
}

void Member::addBook(int bookId) {
    if (bookCount < 5) {
        books[bookCount] = bookId;
        bookCount++;
    }
}

void Member::removeBook(int bookId) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i] == bookId) {
            for (int j = i; j < bookCount - 1; j++)
                books[j] = books[j + 1];
            bookCount--;
            return;
        }
    }
}

bool Member::hasBook(int bookId) const {
    for (int i = 0; i < bookCount; i++) {
        if (books[i] == bookId)
            return true;
    }
    return false;
}

int Member::getBookCount() const {
    return bookCount;
}

int Member::getBook(int i) const {
    return books[i];
}

ostream& LibrarySystem::operator<<(ostream& out, const Member& m) {
    out << m.id << "|" << m.name << "|" << m.phone;
    return out;
}

istream& LibrarySystem::operator>>(istream& in, Member& m) {
    in >> m.id >> m.name >> m.phone;
    return in;
}
