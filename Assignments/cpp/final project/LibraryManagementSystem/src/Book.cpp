#include "../headers/Book.h"
using namespace LibrarySystem;

Book::Book() {
    bookId = 0;
    title = "";
    author = "";
    isbn = "";
    status = BookStatus::AVAILABLE;
    genre = BookGenre::OTHER;
    quantity = 0;
    availableCopies = 0;
}

Book::Book(int id, string title, string author, string isbn, BookGenre genre, int quantity) {
    bookId = id;
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->genre = genre;
    this->quantity = quantity;
    availableCopies = quantity;
    status = BookStatus::AVAILABLE;
}

int Book::getId() const { return bookId; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getAvailableCopies() const { return availableCopies; }
int Book::getQuantity() const { return quantity; }
BookStatus Book::getStatus() const { return status; }

void Book::issue() {
    if (availableCopies > 0) {
        availableCopies--;
        if (availableCopies == 0)
            status = BookStatus::ISSUED;
    }
}

void Book::giveBack() {
    if (availableCopies < quantity) {
        availableCopies++;
        status = BookStatus::AVAILABLE;
    }
}

void Book::display() const {
    cout << "Book ID: " << bookId << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Available: " << availableCopies << endl;
    cout << "Status: " << (status == BookStatus::AVAILABLE ? "AVAILABLE" : "ISSUED") << endl;
}

Book& Book::operator++() {
    quantity++;
    availableCopies++;
    status = BookStatus::AVAILABLE;
    return *this;
}

Book Book::operator++(int) {
    Book temp = *this;
    ++(*this);
    return temp;
}

Book& Book::operator--() {
    if (quantity > 0) {
        quantity--;
        if (availableCopies > quantity)
            availableCopies = quantity;
        if (availableCopies == 0)
            status = BookStatus::ISSUED;
    }
    return *this;
}

bool Book::operator==(const Book& b) const {
    return bookId == b.bookId;
}

bool Book::operator<(const Book& b) const {
    return bookId < b.bookId;
}

string Book::operator[](int index) const {
    if (index == 0) return to_string(bookId);
    if (index == 1) return title;
    if (index == 2) return author;
    if (index == 3) return isbn;
    if (index == 4) return to_string(quantity);
    if (index == 5) return to_string(availableCopies);
    return "";
}

ostream& LibrarySystem::operator<<(ostream& out, const Book& b) {
    out << b.bookId << "|" << b.title << "|" << b.author << "|" << b.isbn << "|"<< b.quantity << "|" << b.availableCopies << "|" << (b.status == BookStatus::AVAILABLE ? 1 : 0);
    return out;
}

istream& LibrarySystem::operator>>(istream& in, Book& b) {
    in >> b.bookId >> b.title >> b.author >> b.isbn >> b.quantity;
    b.availableCopies = b.quantity;
    b.status = BookStatus::AVAILABLE;
    return in;
}
