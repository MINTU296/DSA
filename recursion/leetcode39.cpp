#include <iostream>
#include <vector>
using namespace std;

void combi(vector<int>& arr, int sum, int idx, vector<int>& ans) {
    // Base case: If sum is less than 0 or index is out of bounds
    if (sum < 0 || idx >= arr.size()) {
        return;
    }

    // Base case: If the sum is 0, print the combination
    if (sum == 0) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    // If the current element can be included in the combination
    if (arr[idx] <= sum) {
        ans.push_back(arr[idx]);
        combi(arr, sum - arr[idx], idx, ans);
        ans.pop_back();
    }

    // Recursive call to try the next element
    combi(arr, sum, idx + 1, ans);
}

void findCombinations(vector<int>& arr, int sum, int idx, vector<int>& current) {
    // Base case: If the sum becomes zero, print the current combination
    if (sum == 0) {
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // If the sum becomes negative or we have considered all elements, return
    if (sum < 0 || idx >= arr.size()) {
        return;
    }

    // Include the current element and move to the next step
    current.push_back(arr[idx]);
    findCombinations(arr, sum - arr[idx], idx, current);
    
    // Backtrack by removing the last element
    current.pop_back();

    // Exclude the current element and move to the next step
    findCombinations(arr, sum, idx + 1, current);
}



int main() {
    vector<int> arr = {10,1,2,7,6,1,5};
    vector<int> ans;
    int sum = 8;
    // findCombinations(arr, sum, 0, ans);
    return 0;
}
