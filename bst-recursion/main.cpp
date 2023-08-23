/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node *left;
  Node *right;
  Node(int value){
      data = value;
      left = NULL;
      right = NULL;
  }
};
void insert(Node *&root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        if (root->left == NULL) {
            root->left = new Node(data);
        } else {
            insert(root->left, data); // Recursively insert into the left subtree
        }
    } else {
        if (root->right == NULL) {
            root->right = new Node(data);
        } else {
            insert(root->right, data); // Recursively insert into the right subtree
        }
    }
}

void print_preorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    cout<<curr->data<<endl;
    print_preorder(curr->left);
    print_preorder(curr->right);
}
void print_inorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    print_inorder(curr->left);
    cout<<curr->data<<endl;
    print_inorder(curr->right);
}
void print_postorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    print_postorder(curr->left);
    
    print_postorder(curr->right);
cout<<curr->data<<endl;
    
}
int main()
{
    Node *root = NULL;
   insert(root,6);
   insert(root,3);
   insert(root,8);
   insert(root,2);
   insert(root,5);
   insert(root,7);
   insert(root,9);
//print_preorder(root);
//print_inorder(root);
  print_postorder(root);
    return 0;
}

