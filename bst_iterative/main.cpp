/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

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
void insert(Node*& root,int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        if(data<curr->data){
            if(curr->left == NULL){
                curr->left = new Node(data);
            }
            else{
                s.push(curr->left);
            }
        }
        else{
            if(curr->right == NULL){
                curr->right = new Node(data);
            }
            else{
                s.push(curr->right);
            }
        }
    }
}

void print_inorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    stack<Node*>s;
    while(!s.empty() || curr != NULL){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<endl;
        curr = curr->right;
    }
    cout<<endl;
}
void print_preorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    stack<Node*>s;
    while(!s.empty() || curr != NULL){
        while(curr != NULL){
            cout<<curr->data<<endl;
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}

void preorderIterative(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        cout<<curr->data<<endl;
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
        
    }
}
void print_postorder(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node*>s;
    s.push(root);
    Node *prev = NULL;
    while(!s.empty()){
        Node *curr = s.top();
        if(prev == NULL || prev->left == curr || prev->right == curr){
            if(curr->left){
                s.push(curr->left);
            }
            else if(curr->right){
                s.push(curr->right);
            }
            
        }
        else if(curr->left == prev){
            if(curr->right){
                s.push(curr->right);
            }
        }
        else{
            cout<<curr->data<<endl;
            s.pop();
        }
        prev = curr;
    }
}
void postOrderIterative(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node*>s1,s2;
    s1.push(root);
}
int main()
{
    Node *root = NULL;
    insert(root,6);
    insert(root,3);
    insert(root,8);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    insert(root,9);
    print_inorder(root);
    //print_preorder(root);
    preorderIterative(root);
    //print_postorder(root);
    return 0;
}

