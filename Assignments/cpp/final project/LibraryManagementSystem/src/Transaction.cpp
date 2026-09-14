#include "../headers/Transaction.h"
using namespace LibrarySystem;

int Transaction::nextId = 1;
const double Transaction::fineRate = 5.0;

Transaction::Transaction() {
    transactionId = nextId++;
    memberId = 0;
    bookId = 0;
    fineAmount = 0;
}

Transaction::Transaction(int memberId, int bookId, string issueDate, string dueDate) {
    transactionId = nextId++;
    this->memberId = memberId;
    this->bookId = bookId;
    this->issueDate = issueDate;
    this->dueDate = dueDate;
    returnDate = "";
    fineAmount = 0;
}

int Transaction::getId() const { return transactionId; }
int Transaction::getMemberId() const { return memberId; }
int Transaction::getBookId() const { return bookId; }
bool Transaction::isReturned() const { return returnDate != ""; }

void Transaction::returnBook(string date, int lateDays) {
    returnDate = date;
    if (lateDays > 0)
        fineAmount = lateDays * fineRate;
}

double Transaction::getFine() const {
    return fineAmount;
}

void Transaction::display() const {
    cout << "Transaction ID: " << transactionId << endl;
    cout << "Member ID: " << memberId << endl;
    cout << "Book ID: " << bookId << endl;
    cout << "Issue Date: " << issueDate << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << "Return Date: " << (returnDate == "" ? "Not Returned" : returnDate) << endl;
    cout << "Fine: " << fineAmount << endl;
}
