#include "FileWithTransactions.h"


void FileWithTransactions::addTransactionToFile(Transaction transaction, string fileName) {
    CMarkup xml;

    bool fileExists = xml.Load(fileName);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Transactions");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Transaction");
    xml.IntoElem();
    xml.AddElem("TransactionId", transaction.getTransactionId());
    xml.AddElem("UserId", transaction.getUserId());
    xml.AddElem("Date", transaction.getDate());
    xml.AddElem("Value", transaction.getValue());
    xml.AddElem("KindOfTransaction", transaction.getKindOfTransaction());

    xml.Save(fileName);
}


vector<Transaction> FileWithTransactions::loadTransactionsFromFile(string nameOfFileWithTransactions, int loggedUserId) {
    vector <Transaction> transactions;
    CMarkup xml;
    xml.Load(nameOfFileWithTransactions);
    xml.FindElem("Transactions");
    xml.IntoElem();
    while (xml.FindElem("Transaction")) {
        Transaction transaction;
        xml.IntoElem();
        xml.FindElem("TransactionId");
        transaction.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        transaction.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        transaction.setDate(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Value");
        transaction.setValue(HelpfulFunctions::conversionStringToFloat(xml.GetData()));
        xml.FindElem("KindOfTransaction");
        transaction.setKindOfTransaction(xml.GetData());
        transactions.push_back(transaction);
        xml.OutOfElem();
    }
    return transactions;
}
