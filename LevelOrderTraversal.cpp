// Level Order Traversal BFS
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

vector<vector<int>>levelOrderTraversal(Node*root){
    if(root == NULL) return {};
    
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        // this tells how many nodes are there currently in queue
        int n = q.size();
        // we can now levelWise store elements in there separate array
        vector<int>res;

        for(int i = 0; i < n;i++){
            Node*front = q.front();
            q.pop();
            
            res.push_back(front->data);
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            
        }
        ans.push_back(res);
    }
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
    
    vector<vector<int>>ans = levelOrderTraversal(root);
    int level = 0;
    for(vector<int>res:ans){
        cout<<level<<"-> ";
        for(auto x: res){
            cout<<x<<" ";
        }
        cout<<endl;
        level++;
    }
    return 0;
}