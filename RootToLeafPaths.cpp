
#include<bits/stdc++.h>
using namespace std;    

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node*root,vector<vector<int>>&ans,vector<int>&res){
    if(root==NULL) return ;
    if(root->left == NULL && root->right == NULL){
        res.push_back(root->data);
        ans.push_back(res);
        res.pop_back();
        return ;
    }
    res.push_back(root->data);
    solve(root->left,ans,res);
    solve(root->right,ans,res);
    res.pop_back();
    return;
}

vector<vector<int>> Paths(Node* root) {
    // code here
    vector<vector<int>>ans;
    vector<int>res;
    solve(root,ans,res);
    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = Paths(root);
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}