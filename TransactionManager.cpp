#include "TransactionManager.h"

void TransactionManager::addTransaction(vector<Transaction> &transactions, string fileName, string keyword) {
    Transaction transaction;
    string kinfOfTransaction;
    transaction.setTransactionId(getNewTransactionId(transactions));
    transaction.setUserId(loggedInUser.getUserId());
    char choice = NULL;
    do {
        system("cls");
        cout << "   >>> DODAJ " << keyword << " <<<" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Czy dodac " << keyword << " z dzisiejsza data? (t/n)" << endl;
        cin.sync();
        choice = HelpfulFunctions::getChar();
        switch (choice) {
        case 't':
            transaction.setDate(Date::dateConversionFromStringToInt(Date::getActualDateInString()));
            break;
        case 'n':
            cout << "Wpisz date (yyyy-mm-dd): ";
            transaction.setDate(Date::dateConversionFromStringToInt(Date::getDateFromUser()));
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            break;
        }
    } while(choice != 't' && choice != 'n');
    cout << "Wpisz pochodzenie: " << endl;
    kinfOfTransaction = HelpfulFunctions::getLine();
    transaction.setKindOfTransaction(kinfOfTransaction);
    cout << "Wpisz wartosc: ";
    transaction.setValue(getTransactionValue());
    transactions.push_back(transaction);
    fileWithTransactions.addTransactionToFile(transaction, fileName);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    cout << "Dodano pozycje: " << keyword << "." << endl << endl;
    system("pause");
}


void TransactionManager::addIncome() {
    addTransaction(incomes, INCOMES_FILENAME, "DOCHOD");
}


void TransactionManager::addExpense() {
    addTransaction(expenses, EXPENSES_FILENAME, "WYDATEK");
}


float TransactionManager::getTransactionValue() {
    float transactionValue = NULL;
    return transactionValue = HelpfulFunctions::valueConversionForFloat();
}


int TransactionManager::getNewTransactionId(vector<Transaction> &transactions) {
    if (transactions.empty() == true)
        return 1;
    else
        return transactions.back().getTransactionId() + 1;
}







/*Transaction TransactionManager::giveDataOfNewIncome() {
    Transaction income;
    int userDate;
    double value;
    string kindOfIncome;

    income.setIncomeId(getIdOfLastIncome() + 1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Data uzyskania przychodu: " << endl << endl;
    cout << "1. Dzis. " << endl;
    cout << "2. Inna data. " << endl;

    char choice;
    choice = HelpfulFunctions::getChar();
    if(choice == '1') {
        income.setDate(HelpfulFunctions::dateConversionFromStringToInt(HelpfulFunctions::getDateInString()));
    }
    else if(choice == '2') {
        cout << "Wprowadz date (rrrr-mm-dd): "; // dodac mechanizmy sprawdzajace poprawnosc daty
        userDate = HelpfulFunctions::dateConversionFromStringToInt(HelpfulFunctions::getDateFromUser());
        income.setDate(userDate);
        cout << userDate << endl;
    }

    cout << "Podaj wartosc przychodu: ";
    value = HelpfulFunctions::valueConversionForDouble();
    cout << value; // usunac po fazie testow
    income.setValue(value);
    return income;
}*/
