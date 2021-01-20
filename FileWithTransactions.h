#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "Transaction.h"
#include "HelpfulFunctions.h"

using namespace std;


class FileWithTransactions : public XMLFile {
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    FileWithTransactions(string fileName) : XMLFile(fileName) {};

    void addTransactionToFile(Transaction transaction, string fileName);
    vector<Transaction> loadTransactionsFromFile(string nameFileWithTransactions, int loggedUserId);
};

#endif
