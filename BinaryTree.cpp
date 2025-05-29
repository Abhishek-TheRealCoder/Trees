
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

Node*buildTree(Node*root){
    
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    
    root = new Node(data);
    
    cout<<"Enter the data to be inserted to left of node "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter the data to be inserted to right of node "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void inorder(Node*root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node*root = NULL;
    root = buildTree(root);
    inorder(root);
    return 0;
}