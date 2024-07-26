#include<iostream>
using namespace std;


void heloo(int n){
    if(n==0){
        return;
    }
    cout<<"hellow"<<endl;
    heloo(n-1);
}
int main(){
    heloo(4);
    return 0;
}