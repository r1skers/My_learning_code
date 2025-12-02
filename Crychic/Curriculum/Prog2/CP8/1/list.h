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
    static void print_all(list* head);
    static void remove_all(list* head);
};
#endif