#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <iostream>
#include <vector>

#include "PersonalBudget.h"
#include "User.h"
#include "FileWithUsers.h"


using namespace std;


class MenuManager {
    vector<User> users;
    FileWithUsers fileWithUsers;
    User loggedInUser;

public:
    MenuManager()
     void userRegistration();

};

#endif
