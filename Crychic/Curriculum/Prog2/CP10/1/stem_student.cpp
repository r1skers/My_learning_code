#include "stem_student.h"
#include <iostream>

stem_student :: stem_student()
{
    set("No Name", -1, -1, -1, -1, -1);
    cout<<"default constructor in stem_student is called"<<endl;
}

stem_student :: stem_student(string name, int eng, int math, int info, int chem, int phys)
{
    cout<<"constructor for in stem_student is called"<<endl;
    set(name, eng, math, info, chem, phys);  
}

stem_student :: ~stem_student()
{
    cout<<"destructor for in stem_student is called"<<endl;
}

void stem_student :: calc_ave()
{
    ave = (eng + math + info + chem + phys) / 5;
}

int stem_student :: get_ave()
{
    return ave;
}

void stem_student :: set(string name, int eng, int math, int info, int chem, int phys)
{
    this->name = name;
    this->eng = eng;
    this->math = math;
    this->info = eng;
    this->chem = chem;
    this->phys = phys;
    calc_ave();
}

void stem_student :: print()
{
    cout<<name<<" eng:"<<eng<<" math:"<<math<<" info:"<<info<<" chem:"<<chem<<" phys:"<<phys<<" stem_ave:"<<ave<<endl;
}