#include<iostream>
#include<vector>
using namespace std;

int upper_bound(vector<int> &arr, int val){
    int low=0;
    int high=arr.size()-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==val){
            return arr[mid+1]; // upper bound;
            
        }
        //val lie before the mid;
        else if(arr[mid]>val){
            high=mid-1;
            if(val>arr[mid-1]){
                return arr[mid]; // upper bound
            }
        }
        // val lie after the mid
        else{
            low=mid+1;
            if(val<arr[mid+1]){
                return arr[mid]; // upper bound
                

                
            }
        }
    }
}
int main(){
    vector<int> array = {1, 4, 5, 12, 13, 19,24,30};
    cout<<upper_bound(array,14);
}