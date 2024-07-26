#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void display(Node* root){

    if(root == NULL) return;
    cout<<root->val<< " ";
    display(root->left);
    display(root->right);
    
}

void Sum(Node* root, int *sum){
    if(root == NULL) return;
    *sum+=root->val;
    Sum(root->left,sum);
    Sum(root->right,sum);
}

int SumOf(Node* root){
    if(root==NULL) return 0;
    int leftsum=SumOf(root->left);
    int rightsum=SumOf(root->right);
    return root->val+leftsum+rightsum;
}

void Size(Node* root, int *size){
    if(root == NULL) return;
    *size+=1;
    Size(root->left,size);
    Size(root->right,size);
}

// or
int SizeOf(Node* root){
    if(root==NULL) return 0;
    int leftsum=SizeOf(root->left);
    int rightsum=SizeOf(root->right);
    return 1+leftsum+rightsum;
}

int maxVal(Node* root){
    if(root == NULL) return INT_MIN;
    int Lmax=maxVal(root->left);
    int Rmax=maxVal(root->right);

    return max(root->val,max(Lmax,Rmax));
}
int level(Node* root){
    if(root==NULL) return 0;
    int leftlevel=level(root->left);
    int rightlevel=level(root->right);
    return 1+max(leftlevel,rightlevel);
}
int main(){
    Node* a = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->left = new Node(4);
    a->left->right = new Node(5);

    // connection
    /*  a
       / \
      b   c   
    /      \
    d       NULL
    NULL         */

    display(a);
    cout<<endl;
    int sum=0;
    Sum(a,&sum);
    cout<<sum;
    cout<<endl;
    cout<<SumOf(a);

    cout<<endl;
    int size=0;
    Size(a,&size);
    cout<<size;
    
    cout<<endl<<SizeOf(a);
    cout<<endl<<maxVal(a);
    cout<<endl<<level(a);
    return 0;
}