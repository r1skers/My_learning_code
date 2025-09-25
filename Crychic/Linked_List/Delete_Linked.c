#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* delete_by_value(Node* head, int target_value){
    Node* temp=head;
    while (head != NULL && head->value == target_value) {
        Node* to_delete = head;
        head = head->next;       
        free(to_delete);        
    }
    if (head == NULL) {
        return NULL;
    }
    while(temp->next!=NULL){
        if(temp->next->value==target_value){
            Node *to_delete=temp->next;
            temp->next=temp->next->next;
            free(to_delete);
        }else{
            temp=temp->next;
        }
    }
    return head;
}
int main(){}