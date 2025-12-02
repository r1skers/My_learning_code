#include"students.h"
#include<iostream>

void student::set(string name,int eng,int math){
    this->name=name;
    this->eng=eng;
    this->math=math;
    calc_ave();
}

void student::calc_ave(){
    ave=(eng+math)/2;
}
void student::print(){
    cout<<name<<" "<<eng<<" "<<math<<" "<<ave<<endl;
}