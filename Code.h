#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class codekeep
{
public:
    int* code;
    int* reserve;
    int n = 0;

    void insertcode();
    void coding();
};

void codekeep::insertcode()
{
    string file;
    cout << "Введите имя файла: "; cin >> file;
    ifstream in(file); // окрываем файл для чтения
    in >> n;
    code = new int[n];
    for (int i = 0; i < n; i++) in >> code[i];
}

void codekeep::coding()
{
    int z;
    int l = 1;
    cout << "Что будете вписывать?" << endl;
    cout << "1 - вставить." << endl;
    cout << "2 - убрать." << endl;
    cout << "3 - сложить." << endl;
    cout << "4 - вычесть." << endl;
    cout << "5 - разделить." << endl;
    cout << "6 - умножить." << endl;
    cout << "7 - ввести." << endl;
    cout << "8 - сверить данные." << endl;
    cout << "9 - вывести верхушку." << endl;
    cout << "- - вывести все данные." << endl;
    cout << "0 - завершение." << endl;
    cout << "= - закончить с инструкциями." << endl;

    while (l != 0)
    {
        switch (_getch())
        {
        case '1':
            if (n == 0)
            {
                n += 2;
                code = new int[n];
                code[n - 2] = PUSH;
                cin >> z;
                code[n - 1] = z;
            }
            else
            {
                reserve = new int[n + 2]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 2; i++)
                    reserve[i] = code[i];
                reserve[n - 2] = PUSH;
                cin >> z;
                reserve[n - 1] = z;

                delete[] code;
                n += 2;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '2':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = POP;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = POP;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '3':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = ADD;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = ADD;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '4':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = SUB;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = SUB;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '5':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = DIV;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = DIV;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '6':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = MUL;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = MUL;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '7':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = ENTER;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = ENTER;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '8':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = TEST;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = TEST;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '9':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = PRINT;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = PRINT;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '-':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = RAM;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = RAM;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '0':
            if (n == 0)
            {
                n++;
                code = new int[n];
                code[n - 1] = EXIT;
            }
            else
            {
                reserve = new int[n + 1]; //Так как необходимо загрузить 2 значения в мнемонику.
                for (int i = 0; i < n - 1; i++)
                    reserve[i] = code[i];
                reserve[n - 1] = EXIT;

                delete[] code;
                n++;
                code = new int[n];

                for (int i = 0; i < n; i++)
                    code[i] = reserve[i];
            }
            break;
        case '=': l = 0; break;
        }
    }
}
