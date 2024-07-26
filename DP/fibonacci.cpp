#include<bits/stdc++.h>
using namespace std;

long long fibo(int n,vector<int> &dp){

    // base case
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];

    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    

}

long long fibo_bottomUp(int n,vector<int>&dp){

    dp[1]=1;
    dp[0]=0;

    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}

long long f(int n){
    if(n==0|| n==1) return n;
    return f(n-1)+f(n-2);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    vector<int> DP(n+1);
    cout<<fibo_bottomUp(n,DP);
    cout<<endl;
    cout<<fibo(n,dp);
    cout<<endl;
    cout<<f(n);
    
    return 0;
}