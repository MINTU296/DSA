#include<iostream>
using namespace std;

void print(int n,int x){
    if(x>n){
        return;
    }
    cout<<x<<endl;
    print(n,x+1);
}

// without extra parameter...
void print1toN(int n){
    if(n==0) return; // base
    print1toN(n-1); // call
    cout<<n<<endl; // kamm
}

int main(){
    // print(10,1);
    print1toN(4);
}