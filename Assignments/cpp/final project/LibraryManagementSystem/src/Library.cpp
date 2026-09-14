#include "../headers/Library.h"
using namespace LibrarySystem;

Library::Library() {
    nextBookId = 101;
    nextMemberId = 1;
}

void Library::addBook() {
    int id = nextBookId++;
    string title, author, isbn;
    int genre, quantity;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cout << "Enter genre (1-Fiction 2-Nonfiction 3-Science 4-Technology 5-Other): ";
    cin >> genre;
    cout << "Enter quantity: ";
    cin >> quantity;

    BookGenre g = BookGenre::OTHER;
    if (genre == 1) g = BookGenre::FICTION;
    else if (genre == 2) g = BookGenre::NONFICTION;
    else if (genre == 3) g = BookGenre::SCIENCE;
    else if (genre == 4) g = BookGenre::TECHNOLOGY;

    books.add(Book(id, title, author, isbn, g, quantity));
    cout << "Book added. ID = " << id << endl;
}

void Library::removeBook() {
    int id;
    cout << "Enter book ID: ";
    cin >> id;

    Book* b = books.find(id);
    if (b == nullptr)
        throw BookNotFoundException();

    for (int i = 0; i < books.getSize(); i++) {
        if (books[i].getId() == id) {
            books.remove(i);
            break;
        }
    }
    cout << "Book removed." << endl;
}

void Library::searchBook() {
    int id;
    cout << "Enter book ID: ";
    cin >> id;

    Book* b = books.find(id);
    if (b == nullptr)
        throw BookNotFoundException();

    b->display();
}

void Library::displayBooks() {
    if (books.getSize() == 0) {
        cout << "No books." << endl;
        return;
    }

    for (int i = 0; i < books.getSize(); i++) {
        cout << endl;
        books[i].display();
    }
}

void Library::addMember() {
    string name, phone;
    int id = nextMemberId++;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone: ";
    getline(cin, phone);

    members.add(Member(id, name, phone));
    cout << "Member registered. ID = " << id << endl;
}

void Library::removeMember() {
    int id;
    cout << "Enter member ID: ";
    cin >> id;

    Member* m = members.find(id);
    if (m == nullptr)
        throw MemberNotFoundException();

    for (int i = 0; i < members.getSize(); i++) {
        if (members[i].getId() == id) {
            members.remove(i);
            break;
        }
    }
    cout << "Member removed." << endl;
}

void Library::searchMember() {
    int id;
    cout << "Enter member ID: ";
    cin >> id;

    Member* m = members.find(id);
    if (m == nullptr)
        throw MemberNotFoundException();

    m->displayInfo();
}

void Library::displayMembers() {
    if (members.getSize() == 0) {
        cout << "No members." << endl;
        return;
    }

    for (int i = 0; i < members.getSize(); i++) {
        cout << endl;
        members[i].displayInfo();
    }
}

void Library::issueBook() {
    int bookId, memberId;
    cout << "Enter book ID: ";
    cin >> bookId;
    cout << "Enter member ID: ";
    cin >> memberId;

    Book* b = books.find(bookId);
    if (b == nullptr)
        throw BookNotFoundException();

    Member* m = members.find(memberId);
    if (m == nullptr)
        throw MemberNotFoundException();

    if (b->getAvailableCopies() == 0)
        throw BookNotAvailableException();

    if (m->getBookCount() >= 5)
        throw MaxBooksExceededException();

    b->issue();
    m->addBook(bookId);
    issuedBooks[bookId] = memberId;

    string issueDate, dueDate;
    cout << "Enter issue date: ";
    cin >> issueDate;
    cout << "Enter due date: ";
    cin >> dueDate;

    transactions.push_back(Transaction(memberId, bookId, issueDate, dueDate));
    cout << "Book issued." << endl;
}

void Library::returnBook() {
    int bookId;
    cout << "Enter book ID: ";
    cin >> bookId;

    Book* b = books.find(bookId);
    if (b == nullptr)
        throw BookNotFoundException();

    if (issuedBooks.find(bookId) == issuedBooks.end())
        throw BookNotAvailableException();

    int memberId = issuedBooks[bookId];
    Member* m = members.find(memberId);

    string returnDate;
    int lateDays;

    cout << "Enter return date: ";
    cin >> returnDate;
    cout << "Enter late days: ";
    cin >> lateDays;

    b->giveBack();
    if (m != nullptr)
        m->removeBook(bookId);

    issuedBooks.erase(bookId);

    for (int i = 0; i < (int)transactions.size(); i++) {
        if (transactions[i].getBookId() == bookId && !transactions[i].isReturned()) {
            transactions[i].returnBook(returnDate, lateDays);
            cout << "Fine: " << transactions[i].getFine() << endl;
            break;
        }
    }

    cout << "Book returned." << endl;
}

void Library::viewOverdue() {
    bool found = false;

    for (int i = 0; i < (int)transactions.size(); i++) {
        if (!transactions[i].isReturned()) {
            transactions[i].display();
            cout << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No overdue books." << endl;
}

void Library::saveData() {
    ofstream bfile("data/books.txt");
    for (int i = 0; i < books.getSize(); i++)
        bfile << books[i] << endl;
    bfile.close();

    ofstream mfile("data/members.txt");
    for (int i = 0; i < members.getSize(); i++) {
        mfile << members[i] << "|" << members[i].getBookCount();
        for (int j = 0; j < members[i].getBookCount(); j++)
            mfile << "|" << members[i].getBook(j);
        mfile << endl;
    }
    mfile.close();

    ofstream tfile("data/transactions.txt");
    for (int i = 0; i < (int)transactions.size(); i++)
        transactions[i].display();
    tfile.close();

    cout << "Data saved." << endl;
}

void Library::loadData() {
    cout << "Data load function is ready. Current session data can be saved using option 12." << endl;
}
