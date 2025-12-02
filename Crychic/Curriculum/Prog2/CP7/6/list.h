#ifndef LIST_H
#define LIST_H
#include <string>
#include<iostream>
using namespace std;

class list{
    public:
    string item;
    list*next;
    void set_item(string item);
    list* insert();
    void print();
    void print_all();
    void remove_all();
};
#endif