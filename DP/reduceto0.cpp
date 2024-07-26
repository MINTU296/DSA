#include<bits/stdc++.h>
using namespace std;

int reduceto1(int n){

    if(n==0) return 0;
    if(n<10) return 1;

    int res=INT_MAX;
    int temp=n;

    while(temp!=0){
        int dig = temp%10;
        temp=temp/10;
        
        if(dig!=0){
            return res = min(res, 1 + reduceto1(n-dig));
        }
        
    }
}

vector<int>dp;
int reduceto1_dp(int n) {

    // If n is a single-digit number, only one operation is needed
    if (n < 10) {
        return 1;
    }
    if(dp[n]!=-1) return dp[n];

    int res = INT_MAX;
    int temp = n;

    while (temp != 0) {
        int digit = temp % 10; // Extract the last digit
        temp /= 10; // Remove the last digit

        if (digit != 0) { // To avoid division by zero
            res = min(res, 1 + reduceto1_dp(n - digit)); // Recur with the reduced number
        }
    }
    dp[n] = res;
    return res;
}

int main() {
    // cout << reduceto1(n) << endl;

        int n;
        cin >> n;
        dp.resize(n+10,-1);
        cout<<reduceto1_dp(n);
        dp.clear();

    return 0;
}
