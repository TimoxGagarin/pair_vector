#include <vector>
#include <string>

struct student {
    int id;
    std::string fio;
    int age;
    float average_mark;
    std::string adress;
    std::string telephone_number;
};

student create();
void print(std::vector<student>& arr);
void multi_sort(std::vector<student>& arr);