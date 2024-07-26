#include<iostream>
using namespace std;

void Zig_Zag(int n ){
    if(n==0){
        return;
    }
    cout<<n;
    Zig_Zag(n-1);
    cout<<n;
    Zig_Zag(n-1);
    cout<<n;
}
int main(){
    Zig_Zag(3);
    return 0;
}