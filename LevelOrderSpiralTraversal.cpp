// Spiral Level Order Traversal of a Binary Tree

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

vector<int>findSpiral(Node*root){
    if(root==NULL) return {};
    vector<int>ans;
    
    queue<Node*>q;
    q.push(root);
    bool left_to_right = false;
    
    while(!q.empty()){
        int n = q.size();
        vector<int>res(n,0);
        for(int i = 0;i < n;i++){
            Node*front = q.front();
            q.pop();
            
            int index = left_to_right ? i : n - i - 1;
            res[index] = front->data;
            
            if(front->left){
                q.push(front->left);
            }
            
            if(front->right){
                q.push(front->right);
            }
        }
        left_to_right = !left_to_right;
        for(int i = 0;i < n;i++){
            ans.push_back(res[i]);
        }
    }
    
    return ans;
}


int main() {
    
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int>ans = findSpiral(root);
    for(auto x: ans){
        cout<<x<<" ";
    }

    return 0;
}