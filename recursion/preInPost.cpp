#include<iostream>
using namespace std;

void PIP(int n){
    if(n==0) return;
    cout<<"Pre"<<n<<endl;
    PIP(n-1);
    cout<<"In"<<n<<endl;
    PIP(n-1);
    cout<<"Poat"<<n<<endl;
    
}

int main(){
    PIP(2);
    return 0;
}