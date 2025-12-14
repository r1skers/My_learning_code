#include<stdio.h>
#include<iostream>
using namespace std;

void PrintFuncA();
void PrintFuncB(void);

int main(void){
    printf("start\n");
    PrintFuncA();
    PrintFuncB();
}

void PrintFuncA(){
    cout<<"PrintFuncA"<<endl;
}
void PrintFuncB(){
    cout<<"PrintFuncB"<<endl;
}