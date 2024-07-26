#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr, int inti){
    // base case
    if(inti==arr.size()) return;
    cout<<arr[inti]<<" ";
    print(arr,inti+1);
}

int main(){
    vector<int>arr={5,3,6,2,9,3,2};
    print(arr,0);
    return 0;
}