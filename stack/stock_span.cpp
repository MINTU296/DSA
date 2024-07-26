#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    stack<int> st; // Stack to store indices of the elements
    vector<int> ans(v.size()); // Vector to store the span values
    
    // Span for the first day is always 1
    ans[0] = 1;
    st.push(0); // Push the index of the first element onto the stack
    
    // Iterate over the rest of the elements
    for (int i = 1; i < v.size(); i++) {
        // Pop elements from the stack while stack is
        // not empty and the current element is greater than 
        //the element at the index stored on the top of the stack
        while (!st.empty() && v[i] >= v[st.top()]) {
            st.pop();
        }
        
        // If the stack is empty, it means the current element 
        //is greater than all previous elements
        if (st.empty()) {
            ans[i] = i + 1;
        } else {
            // Otherwise, the span is the difference between
            // the current index and the index of the last higher element
            ans[i] = i - st.top();
        }
        
        // Push the current index onto the stack
        st.push(i);
    }
    
    // Print the calculated span values
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
