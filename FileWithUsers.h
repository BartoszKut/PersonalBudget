#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "Markup.h"
#include "User.h"

using namespace std;


class FileWithUsers : public XMLFile {
    const string NAME_OF_FILE_WITH_USERS;

public:
    FileWithUsers(string fileName) : XMLFile(fileName) {};
    vector<User> loadUsersFromFile();
    void addUserToFile(User user);
    void changePasswordLoggedInUser(User loggedInUser);
    //void changePasswordOfLoggedUser(User(;
};

#endif
