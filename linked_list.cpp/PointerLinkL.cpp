#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
// Traversing the link list
void Display(Node *head){
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}

int size(Node *head){
    int n=0;
    while(head!=NULL)
    {
        head=head->next;
        n++;
    }
    return n;
}

// by recursion
void Dis(Node *temp){
    if(temp==NULL) return;
    cout<<temp->val<<" ";
    Dis(temp=temp->next);
}
int main(){
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    b->val=88; // updating the value
    a->next=b;
    b->next=c;
    c->next=d;
    Dis(a);
    cout<<endl;
    cout<<size(a);
    return 0;
}