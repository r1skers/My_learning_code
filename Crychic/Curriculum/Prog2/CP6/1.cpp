#include<iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double score;
};

int main(){
    Student student;
    student.name = "Alice";
    student.age = 20;
    student.score = 95.5;
    cout << student.name<<" "<< student.age<<" "<<student.score << endl;
}