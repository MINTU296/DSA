#include<bits/stdc++.h>
using namespace std;

vector<int>dp(101,-1);

int f(vector<int> & arr, int idx){

    // single house
    if(idx == arr.size()-1) return arr[idx];
    // two house
    if(idx==arr.size()-2) return max(arr[idx],arr[idx+1]);
    
    return max( (arr[idx] + f(arr, idx + 2)), (0 + f(arr, idx + 1)));
}


int f_dp(vector<int>& arr, int idx) {
        // base case: if idx is out of bounds
        if (idx >= arr.size()) return 0;
        
        // if already computed, return the result
        if (dp[idx] != -1) return dp[idx];
        
        // compute the result for the current idx
        dp[idx] = max(arr[idx] + f_dp(arr, idx + 2), f_dp(arr, idx + 1));
        
        return dp[idx];
} 
int f_td(vector<int>& arr){

    int n = arr.size();
    if(n==1) return dp[0];
    dp.clear();
    dp.resize(n);
    // intial value
    dp[n-1]=arr[n-1];
    dp[n-2]=max(arr[n-1], arr[n-2]);

    for(int i=n-3; i>=0; i--){
        dp[i]=max(arr[i]+dp[i+2], 0+dp[i+2]);
    }

    // ans
    return dp[0];

}

// top-down solution


int main(){
    vector<int>arr={1,2,3,1};
    // cout<<f(arr,0);
    cout<<endl<<f_td(arr);
    return 0;
}