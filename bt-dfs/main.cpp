/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

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
int height(Node *root){
    if(root == NULL){
        return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1+max(left_height,right_height);
}
void processCurrentLevel(Node *root,int l){
    if(root == NULL){
        return;
    }
    if(l==0){
        cout<<root->data<<endl;
        
    }
    else if(l>0){
    processCurrentLevel(root->left,l-1);
    processCurrentLevel(root->right,l-1);
}
        
    }
int main()
{
    //cout<<"Hello World";
    Node *root = NULL;
    insert(root,6);
    insert(root,3);
    insert(root,8);
    insert(root,2);
    insert(root,5);
    insert(root,7);
    insert(root,9);
int h = height(root);
for(int l = 0;l<=h;l++){
    processCurrentLevel(root,l);
}
}