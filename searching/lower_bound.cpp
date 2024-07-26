#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> &arr, int val){
    int low=0;
    int high=arr.size()-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==val){
            return arr[mid-1]; // lower bound;
            
        }
        //val lie before the mid;
        else if(arr[mid]>val){
            high=mid-1;
            if(val>arr[mid-1]){
                return arr[mid-1]; 
            }
        }
        // val lie after the mid
        else{
            low=mid+1;
            if(val<arr[mid+1]){
                return arr[mid];
                

                
            }
        }
    }
}
int main(){
    vector<int> array = {1, 4, 5, 12, 13, 19,24,30};
    cout<<lower_bound(array,11);
}