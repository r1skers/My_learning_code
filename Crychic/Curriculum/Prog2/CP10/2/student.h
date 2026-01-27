#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class student
{
    protected:
        string name;
        int eng;
        int math;
        int ave;
    public:
        student();
        student(string name, int eng, int math);
        ~student();
    public:
        void calc_ave();
        int get_ave();
        void set(string name, int eng, int math);
        void print();
};
#endif