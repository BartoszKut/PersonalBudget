#include <iostream>

#include "PersonalBudget.h"

using namespace std;


int main() {
    char choice = NULL;
    PersonalBudget personalBudget("users.xml","income.xml", "expense.xml");

    while(true) {
        if (personalBudget.isUserLogIn() == false) {
            choice = personalBudget.chooseOptionAtMainMenu();
            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu. Wybierz jedna z opcji: " << endl << endl;
                system("pause");
                break;
            }
        }
        else {
            choice = personalBudget.chooseOptionAtTransactionMenu();
            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
                /*case '3':
                    personalBudget.showBalanceSheetForTheCurrentMonth();
                    break;
                case '4':
                    personalBudget.showBalanceSheetForThePreviousMonth();
                    break;
                case '5':
                    personalBudget.showBalanceSheetForTheSelectedPeriod();
                    break;*/
                case '6':
                    personalBudget.changePasswordOfLoggedUser();
                    break;
                case '7':
                    personalBudget.userLogOut();
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu. Wybierz jedna z opcji: " << endl << endl;
                    system("pause");

            }
        }
    }
    return 0;
}

