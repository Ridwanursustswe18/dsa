#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node* next;
};


node* head = NULL;
node* tail = NULL;

void enqueue(int val) {
    
    
    node* new_node = new node();
    new_node->val = val;
    new_node->next = NULL;
    if(tail == NULL){
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;

    //cout<<tail->val<<endl;
}
void dequeue(){
    if(head == NULL){
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}
void display(){
    node *temp = head;
    while (temp != NULL){
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}
int main() {
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    display();
      dequeue();
      display();

    return 0;
}
