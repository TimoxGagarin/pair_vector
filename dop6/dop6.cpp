#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "student.h"
#include "funcs.h"

using namespace std;

template <class T>
class Vector2F {
    public:
        T x;
        T y;
        Vector2F<T>(T x, T y) {
            this->x = x;
            this->y = y;
        }

        Vector2F<T> operator+(Vector2F<T>& right) {
            return Vector2F<T>(this->x + right.x, this->y + right.y);
        }
        Vector2F<T> operator-(Vector2F<T>& right) {
            return Vector2F<T>(this->x - right.x, this->y - right.y);
        }
        Vector2F<T> operator*(Vector2F<T>& right) {
            return (this->x * right.x - this->y * right.y, this->x * right->y + this->y * right->x);
        }
        //деление точек??
        Vector2F<T> operator/(Vector2F<T>& right) {
            return Vector2F<T>(this->x / right.x , this->y / right.y);
        }

        Vector2F<T> operator+=(Vector2F<T>& right) {
            *this = *this + right;
            return *this;
        }
        Vector2F<T> operator-=(Vector2F<T>& right) {
            *this = *this - right;
            return *this;
        }
        Vector2F<T> operator*=(Vector2F<T>& right) {
            *this = *this * right;
            return *this;
        }
        Vector2F<T> operator/=(Vector2F<T>& right) {
            *this = *this / right;
            return *this;
        }
        string toString() {
            return "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
        }
        T length(Vector2F<T>& other) {
            return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
        }
};

int main(){
    vector<student> school;
    for (int i = 0; i < 10; i++)
        school.push_back(create());

    print(school);
    multi_sort(school);
    print(school);
}