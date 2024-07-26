#include<iostream>
using namespace std;

int gcd(int a, int b){
    // base case
    if(a==0){
        return b;
    }
    else{
        return gcd(b%a,a);
    }
}

int main(){
    cout<<gcd(27,45); // no need to pass maximum value first
    return 0;
}