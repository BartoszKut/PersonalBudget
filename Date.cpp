#include "Date.h"

string Date::conversionIntDateToStringDate(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    str = str.insert(4, "-");
    str = str.insert(7, "-");
    return str;
}


string Date::getDateFromUser() {
    string year, month, day;
    string date = "";
    do {
        getline(cin, date);
        year = date.substr(0, 4);
        month = date.substr(5, 2);
        day = date.substr(8, 2);
    }while (checkCorrectnessOfDate(year, month, day) == false);
    return date;
}


bool Date::checkCorrectnessOfDate(string y, string m, string d) {
    int intY = HelpfulFunctions::conversionStringToInt(y);
    int intM = HelpfulFunctions::conversionStringToInt(m);
    int intD = HelpfulFunctions::conversionStringToInt(d);

    if(intY < 2000 || intY > dateConversionFromStringToInt(getActualDateInString())) {
        cout << "Wprowadz poprawna date." << endl;
        return false;
        }
    else if(intM < 1 || intM > 12) {
          cout << "Wprowadz poprawna date." << endl;
          return false;
        }
    else if ((intM==1 || intM==3 || intM==5 ||  intM==7 || intM==8 || intM==10 || intM==12 ) && (intD > 31)) {
        cout << "Wprowadz poprawna date." << endl;
        return false;
        }
    else if ((intM==4 || intM==6 ||  intM==9 || intM==11 ) && intD > 30) {
        cout << "Wprowadz poprawna date." << endl;
        return false;
        }
    else if ((intY % 4 != 0) && (intM == 2 && intD > 28)) {
        cout << "Wprowadz poprawna date." << endl;
        return false;
        }
    else if ((intY % 4 == 0) && (intM == 2 && intD > 29)) {
        cout << "Wprowadz poprawna date." << endl;
        return false;
        }
    else {
        cout << "Wprowadzono poprawna date. " << endl;
        return true;
        }
}


string Date::getActualDateInString() {
    string year, month, day, date;
    SYSTEMTIME st;
    GetSystemTime(&st);
    year = HelpfulFunctions::conversionIntToString(st.wYear);
    month = HelpfulFunctions::conversionIntToString(st.wMonth);
    if(HelpfulFunctions::conversionStringToInt(month) < 10)
        month = "0" + month;
    day = HelpfulFunctions::conversionIntToString(st.wDay);
    if (HelpfulFunctions::conversionStringToInt(day) <= 9)
         day = "0" + day;
    date = year+ "-" + month+ "-" +day;
    return date;
}


int Date::dateConversionFromStringToInt(string date) {
    string y, m, d;
    int dateInInt;
    y = date.substr(0, 4);
    m = date.substr(5, 2);
    d = date.substr(8, 2);
    return dateInInt = HelpfulFunctions::conversionStringToInt(y+m+d);
}


int Date::setStartDate() {
    int startDate = 0;
    cout << "Podaj date od ktorej sumowac przychody (yyyy-mm-dd): " << endl;
    startDate = dateConversionFromStringToInt(getDateFromUser());
    return startDate;
}


int Date::setEndDate(int startDate) {
    int endDate = 0;
    while (endDate < startDate) {
        cout << "Data koncowa nie moze byc wczesniejsza niz poczatkowa." << endl;

        cout << "Podaj date od ktorej sumowac przychody (yyyy-mm-dd): " << endl;
        startDate = dateConversionFromStringToInt(getDateFromUser());

        cout << "Podaj date do kiedy sumowac przychody (yyyy-mm-dd): " << endl;
        endDate = dateConversionFromStringToInt(getDateFromUser());
    }
}



