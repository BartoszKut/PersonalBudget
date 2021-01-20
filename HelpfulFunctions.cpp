#include "HelpfulFunctions.h"

int HelpfulFunctions::conversionStringToInt(string word) {
    int wordInInt;
    istringstream iss(word);
    iss >> wordInInt;
    return wordInInt;
}


string HelpfulFunctions::conversionIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


string HelpfulFunctions::getLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}


char HelpfulFunctions::getChar() {
    string entry = "";
    char Char = {0};
    while (true) {
        getline(cin, entry);
        if (entry.length() == 1) {
            Char = entry[0];
            break;
        } else cout << "Wprowadziles ciag znakow. Wybierz ponownie: " << endl;
    }
    return Char;
}


float HelpfulFunctions::valueConversionForFloat() {
    float valueInFloat;
    int Length;
    string value;
    do{
        value = getLine();
    } while(!checkCorrectnessOfValue(value));
    value = changeCommaForDot(value);
    return valueInFloat = conversionStringToFloat(value);
}


bool HelpfulFunctions::checkCorrectnessOfValue(string value) {
    int Length = value.length();
    if(Length = 0) {
        cout << "Wprowadz poprawna kwote." << endl;
        return false;
    }

    if(value[0] < 49 || value[0] > 57) {
        cout << "Wprowadz poprawna kwote." << endl;
        return false;
    }

    for(int i = 1; i < Length; i++) {
        if(value[i] < 48 || value[i] > 57 || (value[i] != 44 && value[i] != 46)) {
            cout << "Wprowadz poprawna kwote." << endl;
            return false;
        }
    }
    return true;
}


string HelpfulFunctions::changeCommaForDot(string word) {
    int Length = word.length();
    for (int i = 0; i < Length; i++) {
        if (word[i] == ',') {
            word[i] = '.';
        }
    }
    return word;
}



float HelpfulFunctions::conversionStringToFloat(string str) {
    float numberInDouble = atof(str.c_str());
    return numberInDouble;
}



