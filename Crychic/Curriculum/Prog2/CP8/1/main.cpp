#include<iostream>
#include"list.h"
using namespace std;

int main(){
    list* head=new list;
    head->set_item("head");
    head->next=NULL;

    for(int i=1;i<=5;i++){
        list* new_node=head->insert();
        new_node->set_item("node "+to_string(i));
    }
    list::print_all(head); 
    list::remove_all(head);

}