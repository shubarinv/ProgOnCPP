//
// Created by vhundef on 10.02.19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>


using namespace std;

void openFile(ifstream *file, string fileName) {
    try {
        file->open(fileName);
        if (!file->is_open()) {
            throw runtime_error("Exception-> Could not open file"); //Кидаем исключение если файл не открылся
        }
    }
    catch (exception &e) {
        cout << "Прозошла ошибка при открытии файла: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void openFile(ofstream *file, string fileName) {
    try {
        file->open(fileName);
        if (!file->is_open()) {
            throw runtime_error("Exception-> Could not open file"); //Кидаем исключение если файл не открылся
        }
    }
    catch (exception &e) {
        cout << "Прозошла ошибка при открытии файла: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void filFileContent(string *fileContent, ifstream *file) {
    char buff[1000];
    while (!file->eof()) {
        file->getline(buff, 1000);
        fileContent->append(buff);
        memset(buff, 0, sizeof(buff));
    }
}

bool checkIfFirst(string *str, int charPos) {
    cout << "CheckIfFirst charNum " << charPos << endl;
    string tmp;
    string::iterator strI;
    for (strI = str->begin() + charPos; strI != str->begin(); strI--) {
        tmp = *strI;
        if (tmp == " ")break;
        if (tmp == ".")return true;
    }
    return false;
}

int findStrStartPos(string *str, int charPos){
    int i = charPos;
    string::iterator strI;
    string strTemp;
    for (strI = str->end() - str->length() + charPos - 1; i != 0; strI--) {
        strTemp = *strI;
        if (strTemp == ".")break;
        i--;
    }
    cout<<"Strt pos>>"<<i<<endl;
    return i;
}

void copyStr(string *str, int charPos, string * outStr) {
    int i = 0;
    string tmp;
    string::iterator strI;
    cout << "Char num called startPos: " << charPos << endl;
    cout<<"Before > "<<*outStr<<endl;
    for (strI = str->begin() + findStrStartPos(str, charPos);
         strI != str->end() - (str->length() - charPos - 2); strI++) {
        tmp = *strI;
        *outStr += tmp;
        i++;
    }
    cout<<"After > "<<*outStr<<endl;
}

bool ruIsUpper(unsigned char letter) {
    letter = (unsigned char) letter;
    bool tmp = (letter >= 1040 && letter <= 1071) || letter == 1025;
    cout << "RUISUPPER " << (int) letter << endl;
    cout << "RUISUPPER? " << tmp << endl;
    return (letter >= 1040 && letter <= 1071) || letter == 1025;
}

string processData(string *dataToProcess) {
    unsigned char tmp;
    int i = 0;
    bool flag = false;
    string outStr;

    string::iterator strI;
    for (strI = dataToProcess->begin()+1; strI != dataToProcess->end(); strI++) {
        tmp = static_cast<unsigned char>(*strI);
        cout << "CUR CHAR: " << tmp << endl;

        if (isupper(tmp) || ruIsUpper(tmp)) {
            if (!checkIfFirst(dataToProcess, i)) {
                flag = true;
                cout << "Pos " << i << " REM" << endl;
            }
        }
        if ((tmp == '.') && flag == 0) {
            copyStr(dataToProcess, i, &outStr);
        } else if (tmp == '.') {
            flag = false;
        }
        i++;
    }
    return outStr;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    string inFileName, fileContent;

    if (argc == 2)
        inFileName = argv[1];
    else {
        cout << "Введите название файла: " << endl;
        cin >> inFileName;
    }

    ifstream fileIN;
    openFile(&fileIN, inFileName);
    filFileContent(&fileContent, &fileIN);
    fileIN.close();

    ofstream fileOFF;
    openFile(&fileOFF,inFileName);
    fileOFF<<processData(&fileContent);

    return 0;
}