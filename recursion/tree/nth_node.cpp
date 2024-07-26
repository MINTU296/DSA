#include <iostream>
using namespace std;
#include<queue>

// Definition for a binary tree node
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

//dfs........
void level_node(Node* root, int lev, int n) {
    if (root == NULL) return;
    if (lev == n) {
        cout << root->val << " ";
        return;
    }
    level_node(root->left, lev + 1, n);
    level_node(root->right, lev + 1, n);
}

int level(Node* root){
    if(root==nullptr) return 0;
    int LL=level(root->left); // left level
    int RL=level(root->right); // right level
    return 1+max(LL,RL);
}

void all_level_node(Node* root){
    int x=level(root);
    for(int i=0;i<x;i++){
        cout<<"Node at "<<i<<" level: ";
        level_node(root, 0, i);
        cout<<endl;

    }
}   


// printing level oder using qeue (bfs)
void levelOderQueue(Node* root){
    queue<Node*> q;
    // intial work
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}

int main() {
    // Example usage:
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // int n = 0; // Change n to the desired level
    // cout << "Nodes at level " << n << ": ";
    // level_node(root, 0, n);
    // cout << endl;
    all_level_node(root);
    cout<<endl;
    levelOderQueue(root);


    return 0;
}
