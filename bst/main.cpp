#include <bits/stdc++.h>

using namespace std;

struct node{
    int roll;
    
    node *left,*right;
    node(){
        left = NULL;
        right = NULL;
    }
};

node *root = NULL;

void insert(int roll){
    if(root == NULL){
        node *new_node = new node();
        new_node->roll = roll;
        root = new_node;
    }
    else{
        node *current = root,*parent;
        while(current != NULL){
            if(roll<current->roll){
                parent = current;
                current = current->left;
            }
            else{
                parent = current;
                current = current->right;
            }
        }
        
        node *new_node = new node();
        new_node->roll = roll;
        if(new_node->roll<parent->roll){
            parent->left = new_node;
        }
        else{
            parent->right = new_node;
        }
    }
}
void delete_node(int roll) {
    node* current = root;
    node* parent = NULL;
while(current != NULL && current->roll != roll){
    parent = current;
    if(roll<current->roll){
        current = current->left;
    }
    else if(roll>current->roll){
        current = current->right;
    }
}
if(current == NULL){
    return ;
}
if(current->left == NULL && current->right == NULL){
    if(parent == NULL){
        root = NULL;
    }
    else if(current == parent->left){
        parent->left = NULL;
    }
    else{
        parent->right = NULL;
    }
    delete current;
}
else if(current->left == NULL){
    if(parent == NULL){
        root = current->right;
    }
    else if(current == parent->right){
        parent->right = current->right;
    }
    else{
        parent->left = current->right;
    }
    delete current;
}

else if(current->right==NULL){
    if(parent == NULL){
        root = current->left;
    }
    else if(current == parent->left){
          parent->left = current->left;
    }
    else{
          parent->right = current->left;
    }
    delete current;
}
else{
    parent = current;
    node *successor = current->right;
    while(successor->left!=NULL){
        parent = successor;
        successor = successor->left;
    }
    parent->roll = successor->roll;
    if(parent == current){
        parent->right = successor->right;
    }
    else{
        parent->left = successor->right;
    }
    delete parent;
}
    
}

void print_preorder(node *current){
    if(current == NULL) return;
    cout<<current->roll<<endl;
    print_preorder(current->left);
    print_preorder(current->right);
}

int main(){
    insert(20);
    insert(5);
    insert(25);
    insert(2);
    insert(8);
    insert(30);
    insert(24);
    
    print_preorder(root);
    delete_node(20);
    print_preorder(root);
    return 0;
}




