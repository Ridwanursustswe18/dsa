/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node
{
  int roll;
	node *next;
};
node *root=NULL;
void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node(); //create new node in root
		root->roll=roll;
       root->next=NULL;
	}
	else{
	    node *current_node = root;
	    while(current_node->next != NULL){
	        current_node = current_node->next;
	    }
	    node *new_node = new node();
	    new_node->roll = roll;
	    new_node->next = NULL;
	    current_node->next = new_node;
	}
}
void delete_roll(int roll){
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node->roll != roll){
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node == root){
        node *temp = root;
        root = current_node->next;
        delete(temp);
    }
    else{
        previous_node->next = current_node->next;
        delete(current_node);
    }
}
void add_roll(int roll1,int roll2){
    node *current_node  =root;
    node *previous_node = NULL;
    
    while(current_node->roll != roll1){
        
        current_node = current_node->next;
        
    }
    
    node *new_node = new node();
    new_node->roll = roll2;
    new_node->next = current_node->next;
    current_node->next = new_node;
    
}
void print(){
    node *current_node = root;
    while(current_node != NULL){
        cout<<current_node->roll<<endl;
        current_node = current_node->next;
    }
}
int main(){
	append(1);
	append(2);
	append(6);
	print();
//delete_roll(1);
	//print();
	add_roll(1,4);
	print();
    return 0;
}