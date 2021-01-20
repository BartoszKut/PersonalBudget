#include "Transaction.h"

void Transaction::setTransactionId(int newTransactionId) {
    if (newTransactionId > 0)
        transactionId = newTransactionId;
}


void Transaction::setUserId(int newUserId) {
    if (newUserId > 0)
        userId = newUserId;
}


void Transaction::setDate(int newDate) {
    date = newDate;
}


void Transaction::setValue(double newValue) {
    value = newValue;
}


void Transaction::setKindOfTransaction(string newKindOfTransaction) {
    kindOfTransaction = newKindOfTransaction;
}


int Transaction::getTransactionId() {
    return transactionId;
}


int Transaction::getUserId() {
    return userId;
}


int Transaction::getDate() {
    return date;
}


double Transaction::getValue() {
    return value;
}


string Transaction::getKindOfTransaction() {
    return kindOfTransaction;
}
