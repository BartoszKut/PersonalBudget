#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>
#include <stdlib.h>

#include "HelpfulFunctions.h"

using namespace std;


class Date {

public:
    static int giveStartDate();
    static int giveEndDate();
    static int setStartDate();
    static int setEndDate(int startDate);
    static string getDateFromUser();
    static string getActualDateInString();
    static int dateConversionFromStringToInt(string date);
    static bool checkCorrectnessOfDate(string y, string m, string d);
    static string conversionIntDateToStringDate(int number);
};

#endif
