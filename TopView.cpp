//Top View of Binary Tree
// This code is a C++ implementation to find the top view of a binary tree.
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

vector<int>topView(Node*root){
    if(root==NULL)return {};
    vector<int>ans;
    
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    mp[0] = root->data;
    
    
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i < n;i++){
            Node*front = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = front->data;
            }
            
            if(front->left){
                q.push({front->left,hd - 1});
            }
            
            if(front->right){
                q.push({front->right, hd + 1});
            }
        }
    }
    
    for(auto it : mp){
        ans.push_back(it.second);
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
    
    vector<int>ans = topView(root);
    for(auto x: ans){
        cout<<x<<" ";
    }
    
    return 0;
}