#include<iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double score;
};

int main(){
    Student student[3];
    student[0].name = "Alice";
    student[0].age = 20;
    student[0].score = 95.5;
    student[1].name = "Bob";
    student[1].age = 22;
    student[1].score = 88.0;
    student[2].name = "Charlie";
    student[2].age = 19;
    student[2].score = 92.3;
    for(int i=0;i<3;++i){
        cout << student[i].name<<" "<< student[i].age<<" "<<student[i].score << endl;
    }
}