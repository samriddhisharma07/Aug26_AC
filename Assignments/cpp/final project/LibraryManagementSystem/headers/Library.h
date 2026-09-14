#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Container.h"
#include "Transaction.h"
#include "LibraryException.h"
#include <vector>
#include <map>
#include <fstream>

namespace LibrarySystem {
class Library {
    Container<Book> books;
    Container<Member> members;
    vector<Transaction> transactions;
    map<int, int> issuedBooks;
    int nextBookId;
    int nextMemberId;

public:
    Library();

    void addBook();
    void removeBook();
    void searchBook();
    void displayBooks();

    void addMember();
    void removeMember();
    void searchMember();
    void displayMembers();

    void issueBook();
    void returnBook();
    void viewOverdue();

    void saveData();
    void loadData();
};
}
#endif
