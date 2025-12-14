#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class student{
    public:
    string name;
    int eng;
    int math;
    int ave;
    void calc_ave();
    int get_ave();
};

#endif