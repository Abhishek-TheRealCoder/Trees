



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
int diameter(Node*root){
    if(root == NULL) return 0;
    int left = diameter(root->left);
    int right = diameter(root->right);
    int height = calcHeight(root->left) + calcHeight(root->right) ;
    return max(left, max(right, height));
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);    
    root->right->right = new Node(7);
    
    int ans = diameter(root);
    cout<<ans;
    return 0;
}
