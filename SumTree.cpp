
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


int calc(Node*root){
    if(root==NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    
    int left = calc(root->left);
    int right = calc(root->right);
    return left + right + root->data ;
}




bool isSumTree(Node*root){
    if(root==NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    
    bool left = isSumTree(root->left);
    int leftnode = calc(root->left);
    
    bool right = isSumTree(root->right);
    int rightnode = calc(root->right);
    
    bool cond = leftnode + rightnode == root->data;
    if(cond && left && right) return true;
    else return false;
}

int main() {
    
    Node*root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(10);
    root->left->right = new Node(10);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    
    bool ans = isSumTree(root);
    cout<<ans<<endl;

    return 0;
}