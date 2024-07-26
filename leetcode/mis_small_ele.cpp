#include<iostream>
#include<vector>
using namespace std;

// using binary search

int Find_min(vector<int>arr){
    int low=1; // for tackel outof idx
    int high=arr.size()-1; 
    int min;
    while(low<=high){
        // cout<<"hekl";
        int mid=(low+high)/2;
        if(arr[mid]!=mid){
            min=mid;
        }
        if(arr[mid-1]!=mid-1){
            if(min>mid-1){
                min=mid-1;
                high=mid-1;
            }
            else{
                break;
            }
            
        }
        if(arr[mid+1]!=mid+1){
            if(min>mid+1){
                min=mid+1;
                high=mid+1;
            }
            else{
                break;
            }
            
        }
    }
    return min;;
}

int main(){
    cout<<"By N: ";
    vector<int>arr={0,1,2,3,4,5,6,7,9};
    // cout<<(1/2);
    int min;
    if(arr[0]!=0){
        cout<<0;
    }
    else{
        for(int i=0;i<arr.size();i++){
            if(arr[i+1]-1 > arr[i]){
                min=i+1;
                break;
            }
        }
        cout<<min;
    }

    cout<<endl<<"BY logN: ";
    cout<<Find_min(arr);
    
    return 0;
}