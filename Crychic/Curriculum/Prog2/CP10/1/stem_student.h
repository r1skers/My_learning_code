#ifndef STEM_STUDENT_H
#define STEM_STUDENT_H
#include <string>
#include "student.h"
using namespace std;

class stem_student : public student {
    protected:
        int info;
        int chem;
        int phys;

    public:
        stem_student();
        stem_student(string name, int eng, int math, int info, int chem, int phys);
        ~stem_student();
    public:
        void calc_ave();
        int get_ave();
        void set(string name, int eng, int math, int info, int chem, int phys);
        void print();
};
#endif