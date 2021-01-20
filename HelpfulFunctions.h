#ifndef HELPFULFUNCTIONS_H
#define HELPFULFUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>
#include <stdlib.h>

using namespace std;


class HelpfulFunctions {

public:
    static int conversionStringToInt(string word);
    static string conversionIntToString(int number);
    static string getLine();
    static char getChar();
    static float valueConversionForFloat();
    static string changeCommaForDot(string word);
    static bool checkCorrectnessOfValue(string value);
    static float conversionStringToFloat(string str);


};

#endif
