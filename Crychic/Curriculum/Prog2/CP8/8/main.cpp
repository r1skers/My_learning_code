#include<iostream>
#include"student.h"
using namespace std;

int main(void){
    student yamada("山田一郎",60,70);
    student kato("加藤次郎",50,40);
    student* ptr_takagi=new student("高木三郎",80,60);

    cout<<"some processing"<<endl;

    delete ptr_takagi;
    ptr_takagi=NULL;

    yamada.print();
    kato.print();
}