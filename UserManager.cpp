#include "UserManager.h"

User UserManager::giveDataOfNewUser() {
    User user;

    user.setUserId(getIdOfNewUser());

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}


int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}


bool UserManager::doesLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << "Istnieje uzytkownik o takim loginie. Wprowadz nowy login. " << endl;
            return true;
        }
    }
    return false;
}


string UserManager::changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


void UserManager::userRegistration() {
    system("cls");
    User user = giveDataOfNewUser();
    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << "Konto zalozono pomyslnie." << endl;
    system("pause");
}


void UserManager::userLogIn() {
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = HelpfulFunctions::getLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo " << numberOfAttempts << " prob: ";
                password = HelpfulFunctions::getLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowano. " << endl;
                    loggedInUser.setUserId(itr -> getUserId());
                    loggedInUser.setName(itr -> getName());
                    loggedInUser.setSurname(itr -> getSurname());
                    loggedInUser.setLogin(itr -> getLogin());
                    loggedInUser.setPassword(itr -> getPassword());
                    return;
                }
            }
            cout << "Wprowadzono bledne haslo po raz 3. " << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Brak uzytkownika o takim loginie. " << endl;
    system("pause");
    return;
}


void UserManager::userLogOut() {
    loggedInUser.setLogin("");
    loggedInUser.setPassword("");
    loggedInUser.setName("");
    loggedInUser.setSurname("");
    loggedInUser.setUserId(0);
}


bool UserManager::isUserLogIn() {
    if (loggedInUser.getUserId() > 0) return true;
    else return false;
}


User UserManager::getLoggedInUser() {
    return loggedInUser;
}


void UserManager::changePasswordOfLoggedUser() {
    string newPassword;
    cout << "Podaj nowe haslo: " << endl;
    newPassword = HelpfulFunctions::getLine();
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId () == loggedInUser.getUserId()) {
            users[i].setPassword(newPassword);
            loggedInUser.setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordLoggedInUser(loggedInUser);
}
