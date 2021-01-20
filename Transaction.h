#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
    int transactionId;
    int userId;
    int date;
    double value;
    string kindOfTransaction;

public:
    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setValue(double newValue);
    void setKindOfTransaction(string newKindOfTransaction);

    int getTransactionId();
    int getUserId();
    int getDate();
    double getValue();
    string getKindOfTransaction();
};

#endif
