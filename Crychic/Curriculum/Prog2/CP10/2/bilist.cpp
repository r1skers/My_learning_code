#include "bilist.h"
#include <iostream>
bilist :: bilist() 
{
    next=prev = nullptr;
}

bilist* bilist :: insert()
{
    cout<<"insert in bilist"<<endl;

    bilist* new_node = new bilist();
    if(this->next != nullptr){
        ((bilist*)this->next)->prev = new_node;
    }
    new_node->next = this->next;
    new_node->prev = this;
    this->next = new_node;
    return new_node;
}

void bilist :: remove()
{
    if(this->prev != nullptr){
        this->prev->next = this->next;
    }
    if(this->next != nullptr){
        ((bilist*)this->next)->prev = this->prev;
    }
    delete this;
}