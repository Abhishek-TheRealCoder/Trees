
//Inorder Traversal
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;   
    }

};
// LEFT ROOT RIGHT
void inorder(Node*root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);    
    root->right->right = new Node(7);
    
    inorder(root);
    return 0;
}
