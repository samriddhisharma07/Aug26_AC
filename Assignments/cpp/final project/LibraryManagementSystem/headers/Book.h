#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

namespace LibrarySystem {
enum class BookStatus { AVAILABLE, ISSUED };
enum class BookGenre { FICTION, NONFICTION, SCIENCE, TECHNOLOGY, OTHER };

class Book {
    int bookId;
    string title;
    string author;
    string isbn;
    BookStatus status;
    BookGenre genre;
    int quantity;
    int availableCopies;
public:
    Book();
    Book(int id, string title, string author, string isbn, BookGenre genre, int quantity);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getAvailableCopies() const;
    int getQuantity() const;
    BookStatus getStatus() const;

    void issue();
    void giveBack();
    void display() const;

    Book& operator++();
    Book operator++(int);
    Book& operator--();
    bool operator==(const Book& b) const;
    bool operator<(const Book& b) const;
    string operator[](int index) const;

    friend ostream& operator<<(ostream& out, const Book& b);
    friend istream& operator>>(istream& in, Book& b);
};
}
#endif
