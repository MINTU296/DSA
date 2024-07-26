#include<iostream>
#include<vector>
using namespace std;

int maximum(vector<int> & arr, int i, int max){
    if(i==arr.size()){
        return max;
    }
    else if(arr[i]>max){
        maximum(arr,i+1,arr[i]);
    }
    else{
        maximum(arr,i+1,max);
    }
}

int main(){
    vector<int> arr= {-5,-5,-2,-3,-6,-7};
    cout<<maximum(arr,0,arr[0]);
    return 0;
}