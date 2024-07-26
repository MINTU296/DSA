#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int idx=0;

// dp solution;
int min_oper_dp(int n, vector<int>& store_oper, int count){

    // base case
    if(n==1){
        dp[idx]=count;
        idx++;
        return 1;
    }
    if(dp[idx]!=-1) return dp[idx];

    if(n%2==0){
        dp[idx]=min_oper_dp(n-1,store_oper,count+1);
        dp[idx]=min_oper_dp(n/2,store_oper,count+1);
    }
    if(n%3==0){
        dp[idx]=min_oper_dp(n-1,store_oper,count+1);
        dp[idx]=min_oper_dp(n/3,store_oper,count+1);
    }
} 



// recursive function for minimum operation
void min_oper(int n, vector<int>& store_oper, int count){

    // base case
    if(n==1){
        store_oper.push_back(count);
        return;
    }
    min_oper(n-1,store_oper,count+1);

    if(n%2==0){
        min_oper(n/2,store_oper,count+1);
    }

    if(n%3==0){
        min_oper(n/3,store_oper,count+1);
    }
}  

// another way
int min_oper(int n) {
    // Base case
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;
    
    int one = min_oper(n - 1);
    int div2 = INT_MAX;
    int div3 = INT_MAX;
    
    if (n % 2 == 0) {
        div2 = min_oper(n / 2);
    }

    if (n % 3 == 0) {
        div3 = min_oper(n / 3);
    }

    return 1 + min(one, min(div2, div3));
}

// dp solution

int fdp(int n) {
    // Base case
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    if(dp[n]!=-1) return dp[n];
    
    int one = fdp(n - 1);
    int div2 = INT_MAX;
    int div3 = INT_MAX;
    
    if (n % 2 == 0) {
        div2 = fdp(n / 2);
    }

    if (n % 3 == 0) {
        div3 = fdp(n / 3);
    }

    dp[n]= 1 + min(one, min(div2, div3));
}


// all the above code write by one line

int min_oper_one(int n) {
    // Base case
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    if(dp[n]!=-1) return dp[n];

    return  1 + min( {min_oper(n-1), (n%2==0)? min_oper(n/2) : INT_MAX , (n%3==0)? min_oper(n/3) : INT_MAX} );
}

// dp of solution
int f_dp(int n) {
    // Base case
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    dp[n] =  1 + min( {f_dp(n-1), (n%2==0)? f_dp(n/2) : INT_MAX , (n%3==0)? f_dp(n/3) : INT_MAX} );
}



int main(){
    int n;
    cin>>n;
    dp.resize(n+10,-1);
    vector<int>store_oper;
    // min_oper(n,store_oper,0);

    cout<<f_dp(n);

    // int min_val=store_oper[0];
    // for(int i=0; i<store_oper.size();i++){
    //     cout<<store_oper[i]<<" ";
    //     if(min_val>store_oper[i]){
    //         min_val=store_oper[i];
    //     }
    // }

    // cout<<endl;
    // cout<<min_val;

    return 0;
}