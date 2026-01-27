#include <iostream>
#include "bilist.h"
using namespace std;

int main(){
    bilist* head = new bilist;
    head->set_item("山田太郎", 60, 70);
    
    bilist* node2 = head->insert();
    node2->set_item("加藤次郎", 50, 40);

    bilist* node3 = node2->insert();
    node3->set_item("高木三郎", 80, 60);

    bilist::print_all(head);

    node2->remove();

    cout<<"removed"<<endl;
    bilist::print_all(head);
    bilist::remove_all(head);
}