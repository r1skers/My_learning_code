#include<iostream>
#include"student.h"
using namespace std;

int main(void)
{
    student yamada={"山田太郎", 60, 80};
    yamada.calc_ave();
    cout<<"average is "<<yamada.get_ave()<<endl;
}