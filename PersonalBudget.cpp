#include "PersonalBudget.h"

bool PersonalBudget::isUserLogIn() {
    userManager.isUserLogIn();
}


void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}


void PersonalBudget::userLogIn() {
    userManager.userLogIn();
    if(isUserLogIn() == true) {
        transactionManager = new TransactionManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getLoggedInUser());
        loggedInUser = userManager.getLoggedInUser();
    }
}


void PersonalBudget::userLogOut() {
    userManager.userLogOut();
}


void PersonalBudget::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}


char PersonalBudget::chooseOptionAtMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpfulFunctions::getChar();
    return choice;
}


char PersonalBudget::chooseOptionAtTransactionMenu() {
    char choice;
    system("cls");
    cout << "Imie uzytkownika: " << loggedInUser.getName() << endl;
    cout << "Nazwisko uzytkownika: " << loggedInUser.getSurname() << endl;
    cout << "---------------------------" << endl;
    cout << " >>> MENU OPERACJI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z porzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpfulFunctions::getChar();
    return choice;
}


void PersonalBudget::addIncome() {
    transactionManager -> addIncome();
}


void PersonalBudget::addExpense() {
    transactionManager -> addExpense();
}


void PersonalBudget::showCurrentMonthBalance() {
    transactionManager -> showCurrentMonthBalance();
}


void PersonalBudget::showSelectedPeriodBalance() {
    transactionManager -> showSelectedPeriodBalance();
}


void PersonalBudget::showPreviousMonthBalance() {
    transactionManager -> showPreviousMonthBalance();
}


