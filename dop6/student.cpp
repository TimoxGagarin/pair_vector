#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "student.h"
#include "funcs.h"

using namespace std;

student create() {
    student stud;
    stud.id = time(NULL) - 3600 * 24 * 365 * 53; //seconds since January 1, 2023

    printf("Enter student's FIO: ");
    getline(cin, stud.fio);
    do {
        printf("Enter student's age: ");
        getNum(&stud.age);
    } while (stud.age <= 0);
    do {
        printf("Enter student's average mark: ");
        getFloat(&stud.average_mark);
    } while (stud.average_mark <= 0);
    printf("Enter student's adress: ");
    getline(cin, stud.adress);
    printf("Enter student's telephone number: ");
    getline(cin, stud.telephone_number);
    rewind(stdin);
    return stud;
}

enum field_to_update {
    ID = 1,
    FIO,
    AGE,
    AVERAGE_MARK,
    ADRESS,
    TELEPHONE_NUMBER
};

int comp_ids(const student& a, const student& b)
{
    return (a.id - b.id) < 0;
}
int comp_fio(const student& a, const student& b)
{
    return a.fio < b.fio;
}
int comp_age(const student& a, const student& b)
{
    return (a.age - b.age) > 0;
}
float comp_marks(const student& a, const student& b)
{
    return (a.average_mark - b.average_mark) > 0;
}
float comp_adress(const student& a, const student& b)
{
    return a.adress < b.adress;
}

int condition(student& a, student& b, int task) {
    return (task == ID && comp_ids(a, b)) ||
        (task == FIO && comp_fio(a, b)) ||
        (task == AGE && comp_age(a, b)) ||
        (task == AVERAGE_MARK && comp_marks(a, b)) ||
        (task == ADRESS && comp_adress(a, b));
}

int multi_sort_comprator(vector<int> sorts, student& a, student& b) {
    for (int k : sorts)
        if (condition(a, b, k))
            return condition(a, b, k);
    return 0;
}

void multi_sort(vector<student>& arr) {
    vector<int> sorts;
    while (true) {
        cout << "What would you like to sort?" << endl;
        cout << "1.Id" << endl;
        cout << "2.FIO" << endl;
        cout << "3.Age" << endl;
        cout << "4.Average mark" << endl;
        cout << "5.Adress" << endl;
        cout << "6.Stop" << endl;
        int task;
        do {
            getNum(&task);
        } while (task > 6 || task < 1);
        if (task == 6)
            break;
        sorts.push_back(task);
    }

    for (int i = 1; i < arr.size(); ++i) {
        student el = arr[i];
        int j = i;

        for (; j > 0 && multi_sort_comprator(sorts, el, arr[j - 1]); --j)
            arr[j] = arr[j - 1];
        arr[j] = el;
    }
}

void print_student(student& stud) {
    cout << stud.id << "\t";
    cout << stud.fio << "\t";
    cout << stud.age << "\t";
    cout << stud.average_mark << "\t";
    cout << stud.adress << "\t";
    cout << stud.telephone_number << "\t";
    cout << endl << "----------------------------------------------------------------" << endl;
}

void print(vector<student>& arr) {
    cout << "ID\t" << "FIO\t" << "Age\t" << "Average mark\t" << "Adress\t" << "Telephone number\t" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "School students:" << endl;
    for (int i = 0; i < arr.size(); i++)
        print_student(arr[i]);
}
