/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
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
void dfs_queue(Node *root){
    queue<Node *>s;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.front();
        cout<<curr->data<<endl;
        s.pop();
        if(curr->left){
            s.push(curr->left);
        }
        if(curr->right){
            s.push(curr->right);
        }
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
    //insert(root,5);
    insert(root,7);
    insert(root,9);
    dfs_queue(root);
    return 0;
}
