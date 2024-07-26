#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal
void preOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // Visit the root node
    cout << node->data << " ";
    // Recursively traverse the left subtree
    preOrder(node->left);
    // Recursively traverse the right subtree
    preOrder(node->right);
}

// Inorder traversal function
void inorder(TreeNode* node) {
    if (node == NULL)
        return;
    // Traverse the left subtree
    inorder(node->left);
    // Visit the root node
    cout << node->data << " ";
    // Traverse the right subtree
    inorder(node->right);
}

void PostOrder(TreeNode* node) {
    if (node == NULL)
        return;
    // Traverse the left subtree
    PostOrder(node->left);
    // Traverse the right subtree
    PostOrder(node->right);
    // Visit the root node
    cout << node->data << " ";
}

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // Perform pre-order traversal
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    inorder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    
    // Clean up memory (not strictly necessary in this small example, but good practice)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
