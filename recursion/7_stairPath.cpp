#include<iostream>
using namespace std;

int stairPath(int n){
    if(n==2){
        return 2;
    }
    else if(n==1){
        return 1;
    }
    return stairPath(n-1)+stairPath(n-2);
}

int main(){
    cout<<stairPath(5);
    return 0;
}