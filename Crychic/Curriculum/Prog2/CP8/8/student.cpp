#include"student.h"
#include<iostream>

student::student(string name,int eng,int math){
    cout<<"constructor for "<<name<<" is called"<<endl;
    set(name,eng,math);
}


student::~student(){
    cout<<"destructor for "<<name<<" is called"<<endl;
}

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