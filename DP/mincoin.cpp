#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int min_coins(int x, vector<int>& coins) {
    // base cases
    if (x == 0) return 0;
    if (x < 0) return INT_MAX;
    if (dp[x] != -1) return dp[x];
    
    int res = INT_MAX;
    for (size_t i = 0; i < coins.size(); i++) {
        int sub_res = min_coins(x - coins[i], coins);
        if (sub_res != INT_MAX) {
            res = min(res, 1 + sub_res);
        }
    }
    
    return dp[x] = res;
}

int main() {
    int x, n;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.resize(x + 1, -1);
    int result = min_coins(x, coins);
    cout << (result == INT_MAX ? -1 : result) << endl;

    return 0;
}
