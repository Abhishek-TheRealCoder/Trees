
#include <bits/stdc++.h>
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

void leftView(Node*root,vector<int>&ans){
    
    if(root == NULL || root->left == NULL && root->right == NULL) return ;
    ans.push_back(root->data);
    
    if(root->left){
        leftView(root->left,ans);
    }else{
        leftView(root->right,ans);
    }
    return;
}

void printLeaf(Node*root,vector<int>&ans){
    if(root==NULL ) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ;
    }
    
    printLeaf(root->left,ans);
    
    printLeaf(root->right,ans);
    return ;
}

void rightView(Node*root,vector<int>&ans){
    if(root==NULL || root->left == NULL && root->right == NULL) return ;
    
    if(root->right){
        rightView(root->right,ans);
    }else{
        rightView(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int>boundaryTraversal(Node*root){
    if(root==NULL) return {};
    vector<int>ans;
    ans.push_back(root->data);
    
    //left
    leftView(root->left,ans);
    
    //leaf
    printLeaf(root->left,ans);
    printLeaf(root->right,ans);
    //right
    rightView(root->right,ans);
    return ans;
}


int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int>ans = boundaryTraversal(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;    
}
