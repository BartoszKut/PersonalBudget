#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "User.h"
#include "FileWithUsers.h"
#include "HelpfulFunctions.h"

using namespace std;


class UserManager {
    FileWithUsers fileWithUsers;
    vector <User> users;

    User giveDataOfNewUser();
    User loggedInUser;
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    string changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);

public:
    UserManager(string nameOfFileWithUser) : fileWithUsers(nameOfFileWithUser) {
    loggedInUser.setUserId(0);
    users = fileWithUsers.loadUsersFromFile();// waiting for implementation of this function
    };
    void userRegistration();
    void userLogIn();
    void userLogOut();
    bool isUserLogIn();
    User getLoggedInUser();
    void changePasswordOfLoggedUser();

};

#endif
