#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>

#include "User.h"
#include "HelpfulFunctions.h"
#include "Transaction.h"
#include "FileWithTransactions.h"
#include "Date.h"

using namespace std;

class TransactionManager {
    User loggedInUser;
    FileWithTransactions fileWithTransactions;
    vector<Transaction> incomes;
    vector<Transaction> expenses;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
    float incomesSum;
    float expensesSum;
    float sum;

    /*struct Comparison {
        bool operator()(Transaction first, Transaction second) {
            if(first.getDate() < second.getDate()) {
                return true;
            }
            else {
                return false;
            }
         }
    } dateComparison;*/
    void addTransaction(vector<Transaction> &transactions, string fileName, string keyword);
    float getTransactionValue();
    int getNewTransactionId(vector<Transaction> &transactions);

public:
    TransactionManager (string nameOfFileWithTransactions, User LOGGEDINUSER) : fileWithTransactions(nameOfFileWithTransactions), loggedInUser(LOGGEDINUSER) {
        incomes = fileWithTransactions.loadTransactionsFromFile(INCOMES_FILENAME, loggedInUser.getUserId());
        expenses = fileWithTransactions.loadTransactionsFromFile(EXPENSES_FILENAME, loggedInUser.getUserId());
        sum = 0;
        expensesSum = 0;
        incomesSum = 0;
    };
    void addIncome();
    void addExpense();
    void showSelectedPeriodBalance();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
};

#endif
