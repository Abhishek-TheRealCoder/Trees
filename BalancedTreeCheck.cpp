


//PreOrder Traversal
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

int calcHeight(Node*root){
    if(root==NULL) return 0;
    
    int left = calcHeight(root->left);
    int right = calcHeight(root->right);
    
    return max(left, right) + 1;
}

bool isBalanced(Node*root){
    if(root == NULL) return true;

    bool isleft = isBalanced(root->left);
    int leftH = calcHeight(root->left);

    bool isRight = isBalanced(root->right);
    int rightH = calcHeight(root->right);

    int cond = abs(rightH - leftH) <= 1;

    if(isleft && isRight && cond) return true;
    else return false;
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);    
    root->right->right = new Node(7);
    
    bool ans = isBalanced(root);
    cout<<ans;
    return 0;
}
