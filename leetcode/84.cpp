#include<bits/stdc++.h>
using namespace std;

void next_smaller(vector<int>& ns, vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    ns.resize(n);

    // Iterate from the end of the array
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from stack while stack is not empty and 
        //the top element is greater than or equal to the current element
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty, there is no smaller element to the right
        if (st.empty()) {
            ns[i] = -1;
        } else {
            ns[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }
}

void next_smallerIdx(vector<int>& ns, vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    ns.resize(n);

    // Iterate from the end of the array
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from stack while stack is not empty and 
        //the top element is greater than or equal to the current element
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        // If stack is empty, there is no smaller element to the right
        if (st.empty()) {
            // Use n instead of -1 to handle the boundary condition
            ns[i] = n;
        } else {
            ns[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(i);
    }
}

void previous_smaller_index(vector<int>& ps_index, vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    ps_index.resize(n);

    // Iterate from the beginning of the array
    for (int i = 0; i < n; ++i) {
        // Pop elements from stack while stack is not empty
        // and the top element is greater than or equal to the current element
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        // If stack is empty, there is no smaller element to the left
        if (st.empty()) {
            ps_index[i] = -1;
        } else {
            ps_index[i] = st.top();
        }

        // Push the current index onto the stack
        st.push(i);
    }
}

int main(){
    vector<int>arr={2,1,5,6,2,3};
    vector<int>ns(arr.size());
    vector<int>ps(arr.size());
    next_smallerIdx(ns,arr);
    previous_smaller_index(ps,arr);

    int area;
    int area_max=0;
    int b;
    for(int i=0;i<arr.size();i++){
        b=ns[i]-ps[i]-1;
        area=arr[i]*b;
        if(area>area_max){
            area_max=area;
        }
    }

    cout<<area_max;
}