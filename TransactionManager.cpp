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
    float transactionValue = 0;
    return transactionValue = HelpfulFunctions::getValueConversionForFloat();
}


int TransactionManager::getNewTransactionId(vector<Transaction> &transactions) {
    if (transactions.empty() == true)
        return 1;
    else
        return transactions.back().getTransactionId() + 1;
}


void TransactionManager::showCurrentMonthBalance() {
    showBalanceFromCurrentMonth(incomes, "DOCHODOW", expenses, "WYDATKOW");
}


void TransactionManager::showSelectedPeriodBalance() {
    showBalanceFromSelectedPeriod(incomes, "PRZYCHODOW", expenses, "WYDATKOW");
}


void TransactionManager::showPreviousMonthBalance() {
    showBalanceFromPreviousMonth(incomes, "PRZYCHODOW", expenses, "WYDATKOW");
}


void TransactionManager::showBalanceFromCurrentMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond) {
    system("cls");
    int endDate = Date::dateConversionFromStringToInt(Date::getActualDateInString());
    int startDate = Date::getDateOfFirstDayOfMonth(endDate);

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << Date::conversionIntDateToStringDate(startDate) << " do " << Date::conversionIntDateToStringDate(endDate) << endl;
    float incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    float expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}


float TransactionManager::sortAndDisplayTransactions (vector <Transaction> transactions, string keyword, int startDate, int endDate) {
    vector <Transaction> transactionsOfLoggedUser;

    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i].getUserId() == loggedInUser.getUserId()) {
            transactionsOfLoggedUser.push_back(transactions[i]);
        }
    }
    sort(transactionsOfLoggedUser.begin(), transactionsOfLoggedUser.end(), dateComparison);

    float sum = 0;
    cout << endl << "ZESTAWIENIE " << keyword << endl;

    for(int i = 0; i < transactionsOfLoggedUser.size(); i++) {
        if(transactionsOfLoggedUser[i].getDate() >= startDate && transactionsOfLoggedUser[i].getDate() <= endDate) {
            cout << Date::conversionIntDateToStringDate(transactionsOfLoggedUser[i].getDate()) << " " << transactionsOfLoggedUser[i].getKindOfTransaction() << ": " << transactionsOfLoggedUser[i].getValue() << endl;
            sum += transactionsOfLoggedUser[i].getValue();
        }
    }
    cout << endl << "SUMA " << keyword << " : " << sum << endl;
    return sum;
}


void TransactionManager::showBalanceFromSelectedPeriod(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond) {
    system("cls");
    int startDate = 0;
    cout << "Podaj date rozpoczecia bilansu (yyyy-mm-dd): " << endl;
    startDate = Date::dateConversionFromStringToInt(Date::getDateFromUser());

    int endDate = 0;
    cout << "Podaj date konca bilansu (yyyy-mm-dd): " << endl;

    endDate = Date::dateConversionFromStringToInt(Date::getDateFromUser());

    if (endDate < startDate) {
        cout << "Data koncowa nie moze byc wczesniejsza niz poczatkowa." << endl;

        cout << "Podaj date rozpoczecia bilansu (yyyy-mm-dd): " << endl;
        startDate = Date::dateConversionFromStringToInt(Date::getDateFromUser());


        cout << "Podaj date konca bilansu (yyyy-mm-dd): " << endl;
        endDate = Date::dateConversionFromStringToInt(Date::getDateFromUser());
    }
    system("cls");

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << Date::conversionIntDateToStringDate(startDate) << " do " << Date::conversionIntDateToStringDate(endDate) << endl;
    double incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    double expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}


void TransactionManager::showBalanceFromPreviousMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond) {
    system("cls");

    int startDate = Date::getFirstDayOfPreviousMonth(Date::dateConversionFromStringToInt(Date::getActualDateInString()));

    int endDate = Date::getLastDayOFPreviousMonth(startDate);

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << Date::conversionIntDateToStringDate(startDate) << " do " << Date::conversionIntDateToStringDate(endDate) << endl;
    double incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    double expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}
