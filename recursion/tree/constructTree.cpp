#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to print nodes at a specific level
void level_node(Node* root, int lev, int n) {
    if (root == NULL) return;
    if (lev == n) {
        cout << root->val << " ";
        return;
    }
    level_node(root->left, lev + 1, n);
    level_node(root->right, lev + 1, n);
}

// Function to find the height of the tree
int level(Node* root){
    if (root == nullptr) return 0;
    int LL = level(root->left); // left level
    int RL = level(root->right); // right level
    return 1 + max(LL, RL);
}

// Function to print all levels of the tree
void all_level_node(Node* root){
    int x = level(root);
    for (int i = 0; i < x; i++) {
        cout << "Node at " << i << " level: ";
        level_node(root, 0, i);
        cout << endl;
    }
}   

// Function to construct a binary tree from an array
Node* construct(int size, int arr[]){
    if (size == 0) return NULL;
    queue<Node*> q;
    int i = 1;

    // head of the tree
    Node* root = new Node(arr[0]);
    q.push(root);

    while (!q.empty() && i < size) {
        Node* temp = q.front();
        q.pop();
        Node* L;
        Node* R;

        if (i < size && arr[i] != INT_MIN) L = new Node(arr[i]);
        else L = NULL;
        i++;

        if (i < size && arr[i] != INT_MIN) R = new Node(arr[i]);
        else R = NULL;
        i++;

        temp->left = L;
        temp->right = R;
        if (L != NULL) q.push(L);
        if (R != NULL) q.push(R);
    }
    return root;
}

// Function to print level order using queue (BFS)
void levelOderQueue(Node* root){
    if (root == NULL) return;  // Check if the root is NULL
    queue<Node*> q;
    // Initial work
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 8,3, 4, 8, 6, 0, 8,2,3,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(size, arr);
    
    // Print the tree in level order
    cout << "Level Order Traversal BY QUEUE: ";
    levelOderQueue(root);

    // Print all levels
    all_level_node(root);

    return 0;
}
