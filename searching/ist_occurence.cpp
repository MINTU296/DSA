#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2; // Update mid inside the loop
        if (arr[mid] == target) {
            if(target==arr[mid-1]){
                high=mid-1;
            }

            else return mid; // target found at index mid

        } else if (arr[mid] > target) {
            // target will be found on the left side of mid
            high = mid - 1;
        } else {
            // target will be found on the right side of mid
            low = mid + 1; // Update low to mid + 1
        }
    }
    return -1; // target not found   
}

void ist_last(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    vector<int>output={-1,-1};
    int first=-1;
    int last=-1;
    
    while (low <= high) {
        int mid = (low + high) / 2; // Update mid inside the loop
        if(target==arr[mid]){

            for(int i=mid; i>=0;i--){ // left side
            
                if(target==arr[i]){
                    first=i;
                    
                }
                else{
                    break;
                }
            }
            output[0]={first};
            
            for(int i=mid; i<arr.size();i++){ // left side
            
                if(target==arr[i]){
                    last=i;
                }
                else{
                    break;
                }
            }
            output[1]=last;
        }
        else if( target>arr[mid] ){
            high=mid-1;
        }   
        else{
            low=mid+1;
        }
    }

}

int main() {
    vector<int> array = {3, 4, 5,5,5, 12,12,12, 13,13,13, 19};
    // cout<<Binary_Search(array,12);
    ist_last(array,12);
    
}
