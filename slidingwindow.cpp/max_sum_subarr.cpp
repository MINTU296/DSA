#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 8, 9, 1, 2, 9, 6, 3, 2, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Calculate the sum of the first window of size k
    int preSum = 0;
    for (int i = 0; i < k; i++) {
        preSum += arr[i];
    }

    int maxSum = preSum;
    
    // Sliding window approach using while loop
    int i = 0;
    int j = k;
    while (j < n) {
        int curSum = preSum - arr[i] + arr[j];
        maxSum = max(maxSum, curSum);
        preSum = curSum;
        i++;
        j++;
    }

    cout << "Maximum sum of a subarray of size " << k << " is " << maxSum << endl;
    return 0;
}
