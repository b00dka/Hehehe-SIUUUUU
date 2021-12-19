#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct date {
    int day;
    int month;
    int year;
};
struct Ft {
    string name;
    int64_t NumberAvt;
    int64_t NumberTeh;
    date date;
    int64_t telephone;
    string OtdelRegi;
};
void dopolnit(int& length, Ft*& arr)
{
    system("cls");
    cout << "Введите следующие данные через Enter:\n1)Имя владельца\n2)Номер автомобиля\n3)Номер тех.паспорта\n4)Дата рождения\n\tа)День\n\tб)Месяц\n\td)Год\n5)Телефон\n6)Отдел регистрации ГИБДД" << endl;
    fstream len;
    len.open("length.txt");
    len >> length;
    len.close();
    fstream outFile1;
    outFile1.open("database.txt", ios_base::in);
    for (int i = 0; i < length; i++) {
        outFile1 >> arr[i].name;
        outFile1 >> arr[i].NumberAvt;
        outFile1 >> arr[i].NumberTeh;
        outFile1 >> arr[i].date.day;
        outFile1 >> arr[i].date.month;
        outFile1 >> arr[i].date.year;
        outFile1 >> arr[i].telephone;
        outFile1 >> arr[i].OtdelRegi;
    }
    outFile1.close();
    ofstream outFile("database.txt", ios_base::app);
    Ft* narr = new Ft[length + 1];
    for (int i = 0; i < length; i++) {
        narr[i].name = arr[i].name;
        narr[i].NumberAvt = arr[i].NumberAvt;
        narr[i].NumberTeh = arr[i].NumberTeh;
        narr[i].date.day = arr[i].date.day;
        narr[i].date.month = arr[i].date.month;
        narr[i].date.year = arr[i].date.year;
        narr[i].telephone = arr[i].telephone;
        narr[i].OtdelRegi = arr[i].OtdelRegi;
    }
    cin >> narr[length].name;
    outFile << narr[length].name << "\t";
    cin >> narr[length].NumberAvt;
    outFile << narr[length].NumberAvt << "\t";
    cin >> narr[length].NumberTeh;
    outFile << narr[length].NumberTeh << "\t";
    cin >> narr[length].date.day;
    outFile << narr[length].date.day << "\t";
    cin >> narr[length].date.month;
    outFile << narr[length].date.month << "\t";
    cin >> narr[length].date.year;
    outFile << narr[length].date.year << "\t";
    cin >> narr[length].telephone;
    outFile << narr[length].telephone << "\t";
    cin >> narr[length].OtdelRegi;
    outFile << narr[length].OtdelRegi << "\t\n";
    length += 1;
    fstream len2("length.txt", ios_base::out);
    len2 << length;
    len2.close();
    delete[] arr;
    arr = narr;
    outFile.close();
    int chas = 1;
    while (chas == 1) {
        system("cls");
        cout << "Продолжить ввод?(Да(1)/Нет(0))" << endl;
        cin >> chas;
        switch (chas)
        {
        case 1:
            dopolnit(length, arr);
            break;
        case 0:
            chas = 0;
            break;
        default:
            cout << "Введите 1 или 0\n";
            break;
        }
        break;
    }
}
void search() {
    fstream outFile("database.txt");
    fstream len("length.txt", ios_base::in);
    int length, finde;
    len >> length;
    len.close();
    Ft* narr = new Ft[length];
    for (int i = 0; i < length; i++) {
        outFile >> narr[i].name;
        outFile >> narr[i].NumberAvt;
        outFile >> narr[i].NumberTeh;
        outFile >> narr[i].date.day;
        outFile >> narr[i].date.month;
        outFile >> narr[i].date.year;
        outFile >> narr[i].telephone;
        outFile >> narr[i].OtdelRegi;
    }
    int64_t finded;
    string buff;
    cout << "Введите параметр поиска через Enter:\n1)Имя владельца\n2)Номер автомобиля\n3)Номер тех.паспорта\n4)День рождения\n5)Месяц рождения\n6)Год рождения\n7)Телефон\n8)Отдел регистрации ГИБДД" << endl;;
    cin >> finded;
    bool naideno = false;
    switch (finded)
    {
    case 1:
        cin >> buff;
        for (int i = 0; i < length; i++) {
            if (buff == narr[i].name) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 2:
        cin >> finded;
        for (int i = 0; i < length; i++) {
            if (finded == narr[i].NumberAvt) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 3:
        cin >> finded;
        for (int i = 0; i < length; i++) {
            if (finded == narr[i].NumberTeh) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 4:
        cin >> finde;
        for (int i = 0; i < length; i++) {
            if (finded == narr[i].date.day) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 5:
        cin >> finde;
        for (int i = 0; i < length; i++) {
            if (finde == narr[i].date.month) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 6:
        cin >> finde;
        for (int i = 0; i < length; i++) {
            if (finde == narr[i].date.year) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 7:
        cin >> finded;
        for (int i = 0; i < length; i++) {
            if (finded == narr[i].telephone) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    case 8:
        cin >> buff;
        for (int i = 0; i < length; i++) {
            if (buff == narr[i].OtdelRegi) {
                cout << narr[i].name << "\t";
                cout << narr[i].NumberAvt << "\t";
                cout << narr[i].NumberTeh << "\t";
                cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
                cout << narr[i].telephone << "\t";
                cout << narr[i].OtdelRegi << "\t\n";
                naideno = true;
            }
        }
        if (!naideno)
        {
            cout << "Не найдено!" << endl;
        }
        system("pause");
        break;
    default:
        cout << "Выход" << endl;
        system("pause");
        break;
    }
}   
void show() {
    system("cls");
    cout << "Введите следующие данные через Enter:\n1)Имя владельца\n2)Номер автомобиля\n3)Номер тех.паспорта\n4)Дата рождения\n\tа)День\n\tб)Месяц\n\td)Год\n5)Телефон\n6)Отдел регистрации ГИБДД" << endl;
    fstream outFile("database.txt");
    fstream len4("length.txt", ios_base::in);
    int length;
    len4 >> length;
    len4.close();
    Ft* narr = new Ft[length];
    for (int i = 0; i < length; i++) {
        outFile >> narr[i].name;
        outFile >> narr[i].NumberAvt;
        outFile >> narr[i].NumberTeh;
        outFile >> narr[i].date.day;
        outFile >> narr[i].date.month;
        outFile >> narr[i].date.year;
        outFile >> narr[i].telephone;
        outFile >> narr[i].OtdelRegi;
    }
    for (int i = 0; i < length; i++) {
        cout << narr[i].name << "\t";
        cout << narr[i].NumberAvt << "\t";
        cout << narr[i].NumberTeh << "\t";
        cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
        cout << narr[i].telephone << "\t";
        cout << narr[i].OtdelRegi << "\t\n";
    }
    delete[]narr;
    outFile.close();
}
void sort() {
    int length;
    fstream len, outFile;
    len.open("length.txt");
    len >> length;
    len.close();
    outFile.open("database.txt", ios_base::in);
    Ft* narr = new Ft[length];
    for (int i = 0; i < length; i++) {
        outFile >> narr[i].name;
        outFile >> narr[i].NumberAvt;
        outFile >> narr[i].NumberTeh;
        outFile >> narr[i].date.day;
        outFile >> narr[i].date.month;
        outFile >> narr[i].date.year;
        outFile >> narr[i].telephone;
        outFile >> narr[i].OtdelRegi;
    }
    int finde;
    Ft buff;
    cout << "Введите параметр сортировки:\n1)Имя владельца\n2)Номер автомобиля\n3)Номер тех.паспорта\n4)День рождения\n5)Месяц рождения\n6)Год рождения\n7)Телефон\n8)Отдел регистрации ГИБДД\n9)Выход" << endl;
    cin >> finde;
    switch (finde)
    {
    case 1:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].name < narr[j].name) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 2:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].NumberAvt < narr[j].NumberAvt) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 3:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].NumberTeh < narr[j].NumberTeh) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 4:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].date.day < narr[j].date.day) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 5:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].date.month < narr[j].date.month) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 6:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].date.year < narr[j].date.year) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 7:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].telephone > narr[j].telephone) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    case 8:
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (narr[j + 1].OtdelRegi < narr[j].OtdelRegi) {
                    buff = narr[j];
                    narr[j] = narr[j + 1];
                    narr[j + 1] = buff;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            cout << narr[i].name << "\t";
            cout << narr[i].NumberAvt << "\t";
            cout << narr[i].NumberTeh << "\t";
            cout << narr[i].date.day << "." << narr[i].date.month << "." << narr[i].date.year << "\t";
            cout << narr[i].telephone << "\t";
            cout << narr[i].OtdelRegi << "\t\n";
        }
        system("pause");
        break;
    default:
        cout << "Выход" << endl;
        system("pause");
        break;
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m=1 , length = 0;
    fstream len;
    len.open("length.txt");
    len >> length;
    len.close();
    Ft* d = new Ft[length];
    while (m != 0) {
        system("cls");
        cout << "Меню:\n1)Дополнить\n2)Поиск\n3)Вывод\n4)Сортировка\n5)Для выхода введите любой символ" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
            dopolnit(length, d);
            break;
        case 2:
            search();
            break;
        case 3:
            show();
            system("pause");
            break;
        case 4:
            sort();
            break;
        default:
            break;
        }
    }
    delete[] d;
}