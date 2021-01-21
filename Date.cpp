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
    date = year + "-" + month + "-" + day;
    return date;
}


int Date::dateConversionFromStringToInt(string date) {
    string y, m, d;
    int dateInInt;
    y = date.substr(0, 4);
    m = date.substr(5, 2);
    d = date.substr(8, 2);
    dateInInt = HelpfulFunctions::conversionStringToInt(y+m+d);
    return dateInInt;
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
    return endDate;
}


int Date::getDateOfFirstDayOfMonth(int date) {
    int firstDayOfMonth;
    string dateInString;
    dateInString = conversionIntDateToStringDate(date);
    dateInString = dateInString.replace(8,2, "01");
    firstDayOfMonth = dateConversionFromStringToInt(dateInString);
    return firstDayOfMonth;
}


int Date::getFirstDayOfPreviousMonth(int date) {
    int dateOffirstDayOfPreviousMonth, monthInInt, yearInInt;
    string dateInString, monthInStr, yearInStr, dateInString2;

    dateInString = conversionIntDateToStringDate(date);

    monthInStr = dateInString.substr(5,2);
    monthInInt = HelpfulFunctions::conversionStringToInt(monthInStr);

    yearInStr = dateInString.substr(0,4);
    yearInInt = HelpfulFunctions::conversionStringToInt(monthInStr);

    if(monthInInt == 1){
         monthInInt = 12;
         yearInInt = yearInInt - 1;
    }
    else if(monthInInt > 1) {
         monthInInt = monthInInt - 1;
    }
    monthInStr = HelpfulFunctions::conversionIntToString(monthInInt);
    yearInStr = HelpfulFunctions::conversionIntToString(yearInInt);

    dateInString2 = yearInStr + "-" + monthInStr + "-" + "01";

    dateOffirstDayOfPreviousMonth = dateConversionFromStringToInt(dateInString2);
    return dateOffirstDayOfPreviousMonth;
}


int Date::getLastDayOFPreviousMonth(int previousMonthFirstDayDate) {
    string strY, strM, strD, strDate;
    int intY, intM, intD, finalDate;
    strDate = conversionIntDateToStringDate(previousMonthFirstDayDate);
    strY = strDate.substr(0,4);
    strM = strDate.substr(5,2);
    strD = strDate.substr(8,2);
    intY = HelpfulFunctions::conversionStringToInt(strY);
    intM = HelpfulFunctions::conversionStringToInt(strM);
    intD = HelpfulFunctions::conversionStringToInt(strD);

    if (intM==1 || intM==3 || intM==5 ||  intM==7 || intM==8 || intM==10 || intM==12) {
        strD = "31";
        }
    else if (intM==4 || intM==6 ||  intM==9 || intM==11) {
        strD = "30";
        }
    else if ((intY % 4 != 0) && (intM == 2)) {
        strD = "28";
        }
    else if ((intY % 4 == 0) && (intM == 2)) {
       strD = "29";
        }
    strDate = strY + "-" + strM + "-" + strD;
    finalDate = dateConversionFromStringToInt(strDate);
    return finalDate;
}





