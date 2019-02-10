//
// Created by vhundef on 10.02.19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>


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
    for (strI = str->end() - 2; i!=0; strI--) {
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
    cout<<"Before > "<<*outStr<<endl;
    for (strI = str->begin() + findStrStartPos(str, charPos);
         strI != str->end() - (str->length() - charPos-1); strI++) {
        tmp = *strI;
        *outStr += tmp;
        i++;
    }
    cout<<"After > "<<*outStr<<endl;
}

string processData(string *dataToProcess) {
    char tmp;
    int i = 0,length=dataToProcess->length();
    bool flag = false;
    string outStr;

    string::iterator strI;
    for (strI = dataToProcess->begin()+1; strI != dataToProcess->end(); strI++) {
        tmp = *strI;
        cout << "CUR CHAR: " << tmp << endl;

        if (isupper(tmp)) {
            if (!checkIfFirst(dataToProcess, i)) {
                flag = true;
                cout << "Pos " << i << " REM" << endl;
            }
        }
        if ((tmp == '.') && flag == 0) {
            cout << 6 << endl;
            copyStr(dataToProcess, i, &outStr);
        } else if (tmp == '\n') {
            cout << 7 << endl;
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