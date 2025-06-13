
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void sumOfLeaf(Node*root,int& sum){
    if(root==NULL) return ;
    if(root->left == NULL && root->right == NULL){
        sum+=root->data;
        return;
    }
    sumOfLeaf(root->left,sum);
    sumOfLeaf(root->right,sum);
    return;
    
}


int main() {
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    int sum = 0;
    sumOfLeaf(root,sum);
    cout<<sum<<endl;
    return 0;
}