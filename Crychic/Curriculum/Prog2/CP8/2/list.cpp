#include"student.h"
#include<iostream>
#include"list.h"

void list::set_item(string name, int eng, int math){
    this->item.set(name,eng,math);
}

list* list::insert(){
    list* new_node = new list;
    new_node->next = this->next; 
    this->next = new_node; 
    return new_node; 
}

void list::print_all(list* head){
    list* current=head;
    while(current!=NULL){
        current->item.print();
        current=current->next;
    }
}

void list::print(){
    item.print();
}
void list::remove_all(list* head){
    list* current=head;
    while(current!=NULL){
        list* current_buf=current->next;
        delete current;
        current=current_buf;
    }
}