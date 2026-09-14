#ifndef LIBRARYEXCEPTION_H
#define LIBRARYEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

namespace LibrarySystem {
class LibraryException : public exception {
protected:
    string message;
public:
    LibraryException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BookNotFoundException : public LibraryException {
public:
    BookNotFoundException() : LibraryException("Book not found") {}
};

class MemberNotFoundException : public LibraryException {
public:
    MemberNotFoundException() : LibraryException("Member not found") {}
};

class BookNotAvailableException : public LibraryException {
public:
    BookNotAvailableException() : LibraryException("Book is not available") {}
};

class MaxBooksExceededException : public LibraryException {
public:
    MaxBooksExceededException() : LibraryException("Member has maximum books") {}
};
}
#endif
