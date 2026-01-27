#include "student.h"
#include <iostream>

student :: student()
{
    name="No Name";
    eng=math=-1;
    cout<<"default constructor for "<<name<<"is called"<<endl;
}

student :: student(string name, int eng, int math)
{
    
    cout<<"constructor for "<<name<<" is called"<<endl;
    set(name, eng, math);
}

student :: ~student()
{
    cout<<"destructor for "<<name<<" is called"<<endl;
}   

void student :: calc_ave()
{
    ave = (eng + math) / 2;
}

int student :: get_ave()
{
    return ave;
}

void student :: set(string name, int eng, int math)
{
    this->name = name;
    this->eng = eng;
    this->math = math;
    calc_ave();
}

void student :: print()
{
    cout<<name<<" eng:"<<eng<<" math:"<<math<<" ave:"<<ave<<endl;
}