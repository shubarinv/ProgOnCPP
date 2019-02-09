//
// Created by vhundef on 08.02.19.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*
 * Дан файл, содержащий некоторый текст.
 * Удалить из него все фразы, в которых есть слова, содержащие заглавные буквы (начальную заглавную букву в предложении не учитывать).
 */


int countStrngs(string *file) {
    try {
        cout << "CountStrngs" << endl;
        int counter = 1;
        string::iterator i;
        string strTemp;
        for (i = file->begin(); i != file->end(); i++) {
            strTemp = *i;
            if (strTemp == "\n")
                counter++;
        }
        cout << "countStrngs reported ->" << counter << endl;
        return counter;
    }
    catch (exception &e) {
        cout << "Произошла ошибка при попытке посчитать количество строк" << endl << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

int findStrStartPos(string *inStr, int charPos) {
    try {
        int i = charPos - 1;
        string::iterator strI;
        string strTemp;
        for (strI = inStr->end() - 1; strI != inStr->begin(); strI--) {
            strTemp = *strI;
            if (strTemp == "\n")break;
            i--;
        }
        return i;
    }
    catch (exception &e) {
        cout << "Произошла ошибка при попытке найти начальную позицию" << endl << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}


void copyStr(string *inStr, int charPos, string *outStr) {
    try {
        cout << "CopyStr" << endl;
        int i = 0;
        string tmp;
        string::iterator strI;
        for (strI = inStr->begin() + findStrStartPos(inStr, charPos);
             strI != inStr->end() - (inStr->length() - charPos); strI++) {
            tmp = *strI;
            *outStr += tmp;
            i++;
        }
        cout << "COPY OK" << endl;
    }
    catch (exception &e) {
        cout << "Произошла ошибка при попытке скопировать строку" << endl << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "\n-----==-----\n" << *outStr << endl;
}

bool checkIfFirst(string *content, int charPos) {
    try {
        string tmp;
        string::iterator strI;
        for (strI = content->begin() + charPos; strI != content->begin(); strI--) {
            tmp = *strI;
            if (tmp == " ")break;
            if (tmp == "\n")return true;
        }
        return false;
    }
    catch (exception &e) {
        cout << "Произошла ошибка при попытке проверить заглавный символ" << endl << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void findCapitalChars(string *fileContent, int length, string *outstr) {
    try {
        cout << "\nFind capital chars" << endl;

        char tmp;
        int i = 0, totalStrgs = countStrngs(fileContent);
        bool flag = false;
        string::iterator strI;
        for (strI = fileContent->begin() + 1; strI != fileContent->end(); strI++) {
            tmp = *strI;
            cout << "Current char: " << tmp << endl;
            if (isupper(tmp)) {
                cout << 1 << endl;
                if (!checkIfFirst(fileContent, i)) {
                    flag = true;
                    cout << "Pos " << i << " REM" << endl;
                }
            }
            cout << 2 << endl;
            if (totalStrgs == 1) {
                cout << 3 << endl;
                if (i >= length - 1 && flag == 0) {
                    cout << 3 << endl;
                    copyStr(fileContent, i, outstr);
                }
            } else {
                cout << 5 << endl;
                if ((tmp == '\n') && flag == 0) {
                    cout << 6 << endl;
                    copyStr(fileContent, i, outstr);
                } else if (tmp == '\n') {
                    cout << 7 << endl;
                    flag = false;
                }
            }
            i++; // увеличиваем счетчик строк
            cout << "Итераций осталось " << length - i << endl;
        }
    }
    catch (exception &e) {
        cout << "Произошла ошибка при попытке найти заглавную букву" << endl << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void filFileContent(string *fileContent, ifstream *file) {
    char buff[350];
    while (!file->eof()) {
        file->getline(buff, 350);
        fileContent->append(buff);
        fileContent->append("\n");
        memset(buff, 0, sizeof(buff));
    }
}

int main(int argc, char *argv[]) {

    string inFileName, fileContent, outStr;

    ifstream fileIn; // Created obj file for read only

    //inFileName = argv[1];
    if (argc == 2)
        inFileName = argv[1];

    else
        inFileName = "../IN_lab7_1.txt";

    cout << inFileName << " \n";

    // Чтение файла
    try {
        fileIn.open(inFileName);
        if (!fileIn.is_open()) {
            throw 1; //Кидаем исключение если файл не открылся
        }
    }
    catch (int errCode) {
        cout << "Прозошла ошибка при открытии файла\nкод:" << errCode << endl;
        return errCode;
    }
    filFileContent(&fileContent, &fileIn);
    cout << "GOT \n========\n" << fileContent << "\n==========" << endl << "len " << fileContent.length() << endl;
    fileIn.close();

    findCapitalChars(&fileContent, fileContent.length(), &outStr);


    ofstream fileOut; // Write only
    fileOut << outStr;  // Записываем, то что на вывод в файл
    fileOut.close();

    cout << "\nDone" << endl;
    //system("pause");
    return 0;
}
