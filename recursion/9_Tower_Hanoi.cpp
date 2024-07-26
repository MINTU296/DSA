#include<iostream>
using namespace std;

void TowerHanoi(int n, char S, char H, char D){
    // base case
    if(n==0) return;
    // Source,Destination,Helper
    TowerHanoi(n-1, S, D, H); 
    cout<<S<<"->"<<D<<endl;
    // Helper, Source, Destination
    TowerHanoi(n-1, H, S, D);
}

int main(){
    TowerHanoi(1,'A','B','C');

    return 0;
}