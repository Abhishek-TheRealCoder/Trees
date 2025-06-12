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

void solve(Node*root,vector<int>&ans,vector<int>&res,int target){
    if(root==NULL) return ;
    if(root->data == target){
        res = ans;
        return ;
    }
    
    ans.push_back(root->data);
    solve(root->left,ans,res,target);
    solve(root->right,ans,res,target);
    ans.pop_back();
    return ;
}
// Function should return all the ancestor of the target node
vector<int> Ancestors(struct Node *root, int target) {
    // Code here
    if(root==NULL) return {};
    vector<int>ans;
    vector<int>res;
    solve(root,ans,res,target);
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    int target = 5;
    vector<int> ancestors = Ancestors(root, target);
    
    cout << "Ancestors of " << target << ": ";
    for(int val : ancestors) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}