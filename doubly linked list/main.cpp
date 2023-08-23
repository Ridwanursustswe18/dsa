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
	node *prev;
};
node *root=NULL;
node *tail = NULL;
void append(int roll){
   if(root == NULL){
       node *root = new node();
       root->roll = roll;
       root->prev = NULL;
       tail = root;
   }
   else{
       node *new_node = new node();
       new_node->roll = roll;
       new_node->next = NULL;
       tail->next = new_node;
       tail = tail->next
   }
    
}
int main(){
    	append(5);
    	append(4);
    return 0;
}
    



