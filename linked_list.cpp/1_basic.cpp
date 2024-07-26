#include<iostream>
using namespace std;

class Node{
public:
  int val;
  Node* Next;
  // constructor
  Node(int val){
    this->val=val;
    this->Next=NULL;
  }
};

int main(){
  Node a(10),b(20),c(30),d(40);
  // forming the link list
  a.Next=&b;
  b.Next=&c;
  c.Next=&d;
  d.Next=NULL;
  return 0;
}