#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& nums) {
        int rot= nums.size()-1;
        bool flag=true;
        // rotating the array
        for(int i = 0 ; i < rot; i++){
            for(int p=0;p<nums.size();p++){
                cout<<nums[p]<<" ";
            }
            cout<<endl;
            int count=0;
            for(int k = 0; k<nums.size(); k++){
                if(nums[k]<nums[k+1]){
                    count++;
                }
            }
            if(count==nums.size()){
                flag=true;
                break;
            }
            else{
                flag=false;  
            }
            for(int j = nums.size()-1; j > 0; j-- ){
                swap(nums[j],nums[j-1]);
            } 
            
        }
        return flag;
        
    }


bool check1(vector<int>& nums) {
        int n;
        n=nums.size();
        int count=0;
        for( int i = 1 ; i < n ; i++ ){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]){
            count++;
        }
        int flag=1;
        if(count==1){
            flag=1;
        }
        else if(count ==0 ){ // when all the elements are same
            flag=1;
        }

        else{
            flag=0;
        }
        return flag;
    }

int main(){
    vector<int>array = {3,4,5,1,2};
    cout<<check1(array);
}