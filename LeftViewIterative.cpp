
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;   
    }
};

vector<int>leftView(Node*root){
    if(root == NULL) return {};
    vector<int>ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i < n;i++){
            Node*front = q.front();
            q.pop();

            if(i == 0){
                ans.push_back(front->data);
            }

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }
    }
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

    vector<int>ans = leftView(root);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}