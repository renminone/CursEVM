#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include "Mnemonics.h"
#include "Code.h"

using namespace std;

codekeep VMD;
stack VMC; //Объект ВМ.
bool VM = true; //Контроль работы ВМ.
int ip = 0; // Указатель на инструкцию

void codes()
{
    int x;
    cout << "Выберите действие: " << endl;
    cout << "1 - запись из файла." << endl;
    cout << "2 - самостоятельное задать алгоритм" << endl;
    cin >> x;
    if (x == 1)
        VMD.insertcode();
    if (x == 2)
        VMD.coding();
}

// Трансляция кода VM
void decoder(int instr)
{
    switch (instr)
    {
    case PUSH:
    {
        // Проверяем, есть ли место в памяти
        if (VMC.full_sp())
        {
            cout << "Память переполнена!\n";
            break;
        }
        VMC.sp++; // Перемещаемся в свободную ячейку памяти
        VMC.st[VMC.sp] = VMD.code[++ip]; // В массиве кода берем следующее за мнемоникой PUSH значение и кладем его в ячейку памяти
        break;
    }
    case POP:
    {
        if (VMC.empty_sp()) { cout << "Память пуста!\n"; break; } // Проверка памяти на пустоту
        int pop_value = VMC.st[VMC.sp--]; // Берем значение с верхушки стека и выводим его
        printf("Итог: %d \n", pop_value);
        break;
    }
    case ADD:
    {
        // Берем два верхних значения стека
        int a = VMC.st[VMC.sp--];
        int b = VMC.st[VMC.sp--];
        VMC.sp++;
        VMC.st[VMC.sp] = b + a; // Складываем их и кладем результат на стек
        cout << "ADD->"; // Выводим сообщение
        break;
    }
    case SUB:
    {
        // Берем два верхних значения стека
        int a = VMC.st[VMC.sp--];
        int b = VMC.st[VMC.sp--];
        VMC.sp++;
        VMC.st[VMC.sp] = a - b; // Вычитаем их и кладем результат на стек
        cout << "SUB->"; // Выводим сообщение
        break;
    }
    case DIV:
    {
        // Берем два верхних значения стека
        int a = VMC.st[VMC.sp--];
        int b = VMC.st[VMC.sp--];
        VMC.sp++;
        // Делим их и кладем результат на стек
        VMC.st[VMC.sp] = a / b;
        // Выводим сообщение
        cout << "DIV->";
        break;
    }
    case MUL:
    {
        // Берем два верхних значения стека
        int a = VMC.st[VMC.sp--];
        int b = VMC.st[VMC.sp--];
        VMC.sp++;
        VMC.st[VMC.sp] = a * b; // Перемножаем их и кладем результат на стек
        cout << "DIV->"; // Выводим сообщение
        break;
    }
    case RAM:
    {
        //Вывод всех значений массива
        int x = VMC.sp;
        for (; x >= 0; --x)
        {
            printf("RAM[%u]: %u\n", x, VMC.st[x]);
        }
        break;
    }
    case TEST:
    {
        // Сверка верхнего значения стека с числом 0x31337. Если числа совпадают, выводится сообщение «Good Pass!», иначе «Bad Pass!»
        VMC.st[VMC.sp--] == 0x31337 ? printf("Успех!\n") : printf("Неудача!\n");
        break;
    }
    case PRINT:
    {
        printf("PRINT Stack[%u]: %u\n", VMC.sp, VMC.st[VMC.sp]);
        break;
    }
    case ENTER:
    {
       cout << "ENTER Пароль: ";
        
        VMC.sp++; // Перемещаемся вверх по памяти и при помощи scanf_s записываем данные в наш массив. Введенные данные окажутся на верхушке массива.
        scanf_s("%i", &VMC.st[VMC.sp]);
        break;
    }
    case EXIT:
    {
        VM = false; // Установка глобальной переменной в FALSE, чтобы прервать работу VM
        cout << "Виртуальная машина остановлена.\n";
        break;
    }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    codes();
    while (VM)
    { 
        decoder(VMD.code[ip]);
        ip++;
    }
    system("pause");
    return 0;
}
