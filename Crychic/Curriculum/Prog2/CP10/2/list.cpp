#include "list.h"

void list :: set_item(string name, int eng, int math)
{
    this->item.set(name, eng, math);
}

list* list :: insert()
{
    list* new_node = new list();
    new_node->next = this->next;
    this->next = new_node;
    return new_node;
}

void list :: print()
{
    item.print();
}

void list :: print_all(list* head)
{
    list* current = head;
    while(current != nullptr){
        current->item.print();
        current = current->next;
    }
}

void list :: remove_all(list* head)
{
    list* current = head;
    while(current != nullptr){
        list* current_buf=current->next;
        delete current;
        current = current_buf;
    }
}
void list :: print_all()
{
    list* current = this;
    while(current != nullptr){
        current->item.print();
        current = current->next;
    }
}

void list :: remove_all()
{
    list* current = this;
    while(current != nullptr){
        list* current_buf=current->next;
        delete current;
        current = current_buf;
    }
}