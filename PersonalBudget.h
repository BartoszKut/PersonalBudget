#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "UserManager.h"
#include "TransactionManager.h"
#include "HelpfulFunctions.h"

using namespace std;


class PersonalBudget {
    UserManager userManager;
    User loggedInUser;
    TransactionManager *transactionManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;
    const string NAME_OF_FILE_WITH_TRANSACTIONS;


public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses) {
        transactionManager = NULL;
    };
    ~PersonalBudget() {
        delete transactionManager;
        transactionManager = NULL;
    }
    char chooseOptionAtMainMenu();
    char chooseOptionAtTransactionMenu();
    bool isUserLogIn();
    void userRegistration();
    void userLogIn();
    void addIncome();
    void addExpense();
    void userLogOut();
    void changePasswordOfLoggedUser();
};

#endif
