#include<iostream>
using namespace std;

class base_class{
    public:
        void print(void){cout<<"print function in class base_class"<<endl;}
        //virtual void print(void){cout<<"print function in class base_class"<<endl;}

};

class derived_class_A:public base_class{
    public:
        void print(void){cout<<"print function in class derived_class_A"<<endl;}
        //void print(void){cout<<"print function in class derived_class_A"<<endl;}
};

class derived_class_B:public base_class{
    public:
        void print(void){cout<<"print function in class derived_class_B"<<endl;}
        //void print(void){cout<<"print function in class derived_class_B"<<endl;}
};

class derived_class_C:public base_class{
    public:
        void print(void){cout<<"print function in class derived_class_C"<<endl;}
        //void print(void){cout<<"print function in class derived_class_C"<<endl;}
};

int main(void){
    base_class base;
    derived_class_A a;
    derived_class_B b;
    derived_class_C c;

    base.print();
    a.print();
    b.print();
    c.print();

    base_class* ptr_A_as_base=&a;
    derived_class_A* ptr_A=&a;
    ptr_A_as_base->print();
    ptr_A->print();

    base_class* array[3];
    array[0] = &a;
    array[1] = &b;
    array[2] = &c;

    for(int i=0;i<3;i++){
        array[i]->print();
    }
}