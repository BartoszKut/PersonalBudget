#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <vector>

#include"Markup.h"
#include "Transaction.h"
#include "HelpfulFunctions.h"

using namespace std;


class FileWithTransactions {
    //const string NAME_OF_FILE_WITH_INCOMES;
    //const string NAME_OF_FILE_WITH_EXPENSES;

public:
    void addTransactionToFile(Transaction transaction, string nameFileWithTransactions);
    vector<Transaction> loadTransactionsFromFile(string nameFileWithTransactions, int loggedUserId);
};

#endif
