#include <bits/stdc++.h>
using namespace std;

void next_greater(vector<int>& arr, vector<int>& ans) {
    stack<int> st;
    int n = arr.size();
    ans.resize(n);
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
}

void previous_greater(vector<int>& arr, vector<int>& ans) {
    stack<int> St;
    // Resize the ans vector to be the same size as arr
    ans.resize(arr.size());
    
    // Initial work for the first element
    ans[0] = -1;  // No previous element for the first element
    St.push(arr[0]);  // Push the first element onto the stack

    // Iterate through the array starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        // Pop elements from the stack while the stack is not empty 
        //and the current element is greater than or equal to the top 
        //element of the stack
        while (!St.empty() && arr[i] >= St.top()) {
            St.pop();
        }
        
        // If the stack is empty, no previous greater element exists
        if (St.empty()) {
            ans[i] = -1;
        } else {
            // The top element of the stack is the previous greater element
            ans[i] = St.top();
        }
        
        // Push the current element onto the stack
        St.push(arr[i]);
    }
}

int main() {
    vector<int> arr = {4, 5, 9, 0, 1, 6, 2, 1, 2};
    vector<int> ans;
    vector<int> ans1;
    next_greater(arr, ans);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
    previous_greater(arr, ans1);
    
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " ";
    }

    return 0;
}
