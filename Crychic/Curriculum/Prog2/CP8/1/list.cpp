#include"list.h"

void list::set_item(string item){
    this->item=item;
}

list* list::insert(){
    list* new_node = new list;
    new_node->next = this->next; 
    this->next = new_node; 
    return new_node; 
}
void list::print(){
    cout<<item<<endl;
}

void list::print_all(list* head){
    list* current=head;
    while(current!=NULL){
        cout<<current->item<<endl;
        current=current->next;
    }
}

void list::remove_all(list* head){
    list* current=head;
    while(current!=NULL){
        list* current_buf=current->next;
        delete current;
        current=current_buf;
    }
}