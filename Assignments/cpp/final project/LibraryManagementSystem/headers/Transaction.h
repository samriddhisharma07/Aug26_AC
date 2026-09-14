#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
using namespace std;

namespace LibrarySystem {
class Transaction {
    static int nextId;
    static const double fineRate;
    int transactionId;
    int memberId;
    int bookId;
    string issueDate;
    string dueDate;
    string returnDate;
    double fineAmount;
public:
    Transaction();
    Transaction(int memberId, int bookId, string issueDate, string dueDate);
    int getId() const;
    int getMemberId() const;
    int getBookId() const;
    bool isReturned() const;
    void returnBook(string date, int lateDays);
    double getFine() const;
    void display() const;
};
}
#endif
