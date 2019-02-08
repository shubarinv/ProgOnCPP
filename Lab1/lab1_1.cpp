//
// Created by vhundef on 08.02.19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <iostream>

/*
 * Дан файл, содержащий некоторый текст.
 * Удалить из него все фразы, в которых есть слова, содержащие заглавные буквы (начальную заглавную букву в предложении не учитывать).
 */

int countChars(FILE *file) {
    int counter = 0;
    while (fgetc(file) != EOF) {  // в цикле проходим весь файл посимвольно
        counter++; // то увеличиваем счетчик строк
    }
    fseek(file, 0, SEEK_SET);
    return counter;
}

int countStrngs(char *file, int length) {
    char tmp;
    int counter = 1, i = 0;
    while (i < length) {
        tmp = file[i];
        i++;
        if (tmp == '\n')
            counter++;
    }
    return counter;
}

int findStrStartPos(char *string, int charPos) {
    int i;
    for (i = charPos - 1; (int) string[i] != '\n' && i >= 0; i--);
    return i;
}


void copyStr(char *string, int charPos, char *outstr, int *tmp) {
    int i = 0;
    // printf("\n====CopyStr INVOKED====\n");
    for (i = findStrStartPos(string, charPos) + 1; i <= charPos; i++) {
        outstr[*tmp] = string[i];
        *tmp += 1;
        //     printf("tmp is now%d\n", *tmp);
    }
}

int checkIfFirst(char *content, int charPos) {
    // printf("\n=========\nCheckIfFirst\n=========\n");
    int i;
    for (i = charPos; content[i] != ' ' && i >= 0; i--) {
        if ((int) content[i] == '\n') {
            //          printf("\nPOS:%d\n", i);
            return 1;
        }
    }
    //   printf("\n---------\n");
    return 0;
}

void findCapitalChars(char *fileContent, int length, char *outstr, int *secTmp) {
    //   printf("\n=========\nFindCapChars\n=========\n");
    int i = 1, tmp, flag = 0;
    while (i < length) {  // в цикле проходим весь файл посимвольно
        tmp = fileContent[i];
        //    printf("Current char %c\n", (char) tmp);
        if (isupper(tmp))
            if (!checkIfFirst(fileContent, i)) {
                flag = 1;
                // printf("TO REM\n");
            }
        if (countStrngs(fileContent, length) == 1) {
            if (i >= length - 1 && flag == 0)
                copyStr(fileContent, i, outstr, secTmp);
        } else {
            if (((char) tmp == '\n') && flag == 0) {
                copyStr(fileContent, i, outstr, secTmp);
            } else if (tmp == '\n') {
                flag = 0;
                //       printf("+++++++++++++++");
            }
        }
        i++; // то увеличиваем счетчик строк
//        printf("\nIterations left %d\n", length - i);
    }
//    printf("\n-------------\n");
}


void fillArray(FILE *file, char *array) {
    //  printf("\n=========\nFillArray\n=========\n");
    int i = 0, tmp;
    while ((tmp = fgetc(file)) != EOF) {  // в цикле проходим весь файл посимвольно
        // printf("Current char %c\n", (char) tmp);
        array[i] = (char) tmp;
        i++; // то увеличиваем счетчик строк
    }
}

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "rus");
    // Обработка переданных аргументов
    char *inFileName = NULL, *fileContent = NULL, *outStr = NULL;

    int totalCharsInFile, tmp = 0;
    FILE *file;

    //inFileName = argv[1];
    if (argc == 2)
        inFileName = argv[1];

    else
        inFileName = "../IN_lab7_1.txt";

    puts(inFileName);
    // Чтение файла
    if ((file = fopen(inFileName, "r")) == NULL) {
        perror("Ошибка открытия файла");
        return -0xF;
    }
    //Считаем количество строк
    totalCharsInFile = countChars(file);
    fileContent = (char *) malloc(sizeof(char) * totalCharsInFile);
    outStr = (char *) malloc(sizeof(char) * totalCharsInFile);
    fillArray(file, fileContent);
    findCapitalChars(fileContent, totalCharsInFile, outStr, &tmp);
    fclose(file);

    file = fopen(inFileName, "w");
    fputs(outStr, file);
    fclose(file);
    printf("\nDone\n");
    //system("pause");
    return 0;
}