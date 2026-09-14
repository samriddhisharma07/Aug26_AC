#ifndef MEMBER_H
#define MEMBER_H
#include "Person.h"

namespace LibrarySystem {
class Member : public Person {
    int bookCount;
    int *books;
public:
    Member();
    Member(int id, string name, string phone);
    Member(const Member &m);
    Member& operator=(const Member &m);
    bool operator==(const Member &m) const;
    ~Member();

    void displayInfo() const override;
    void addBook(int bookId);
    void removeBook(int bookId);
    bool hasBook(int bookId) const;
    int getBookCount() const;
    int getBook(int i) const;

    friend ostream& operator<<(ostream& out, const Member& m);
    friend istream& operator>>(istream& in, Member& m);
};
}
#endif
