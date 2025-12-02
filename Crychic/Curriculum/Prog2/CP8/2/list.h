#ifndef LIST_H
#define LIST_H
#include "student.h"
#include<iostream>
using namespace std;

class list{
    public:
        student item;
        list* next;

        void set_item(string name, int eng, int math);
        list* insert();

        void print();
        void print_all();
        void remove_all();
        static void print_all(list* head);
        static void remove_all(list* head);
};

#endif