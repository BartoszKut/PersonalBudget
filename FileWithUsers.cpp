#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());
}


vector<User> FileWithUsers::loadUsersFromFile() {
    vector <User> users;
    CMarkup xml;
    xml.Load(getFileName());
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User")) {
        User user;
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}


void FileWithUsers::changePasswordLoggedInUser(User loggedInUser) {
    CMarkup xml;
    xml.Load(getFileName());
    while (xml.FindChildElem("User")) {
        xml.IntoElem();
        xml.FindChildElem("UserId");
        if (atoi(xml.GetChildData().c_str()) == loggedInUser.getUserId()) {
            xml.FindChildElem("Password");
            xml.RemoveChildElem();
            xml.AddChildElem("Password", loggedInUser.getPassword());
            xml.Save(getFileName());
            return;
        }
        xml.OutOfElem();
    }
}


