
#include <bits/stdc++.h>
using namespace std;    

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


void solve(Node*root,int x,vector<Node*>&ans,vector<Node*>&res){
    if(root==NULL) return;
    
    if(root->data == x){
        ans.push_back(root);
        res = ans;
        return;
    }
    
    ans.push_back(root);
    solve(root->left,x,ans,res);
    solve(root->right,x,ans,res);
    ans.pop_back();
    return;
    
}
// Function to return the lowest common ancestor in a Binary Tree.
Node* lca(Node* root, int n1, int n2) {
    // Your code here
    if(root==NULL) return NULL;
    vector<Node*>first,second,ans;
    
    solve(root,n1,ans,first);
    ans.clear();
    solve(root,n2,ans,second);
    
    map<Node*,int>mp;
    for(auto x : second){
        mp[x]++;
    }
    
    int n = first.size();
    for(int i = n-1;i >= 0;i--){
        if(mp.find(first[i])!=mp.end()){
            return first[i];
        }
    }
    return NULL;
}

int main(){
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    int n1 = 4, n2 = 5;
    Node* ancestor = lca(root, n1, n2);
    
    if (ancestor) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << ": " << ancestor->data << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}