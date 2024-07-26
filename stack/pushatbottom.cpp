#include <bits/stdc++.h>
using namespace std;

// Function to push an element to the bottom of the stack
void PushBottom(stack<int>& st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int x = st.top();
    st.pop(); // Popping elements
    PushBottom(st, ele);
    st.push(x); // Push popped element back again
}

// Function to reverse the stack
void ReverseStack(stack<int>& st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    ReverseStack(st);
    PushBottom(st, x);
}

// Function to display the stack from top to bottom
void Display(stack<int>& st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    cout << x << " ";
    Display(st); // Recursive call to display remaining stack
    st.push(x); // Push the element back to preserve the stack
}

int main(){
    stack<int> st;
    st.push(10);  // 10
    st.push(20);  // 20
    st.push(30);  // 30
    st.push(40);  // 40

    // Display the stack
    cout << "Original stack: ";
    Display(st);
    cout << endl;

    // Push 7 to the bottom of the stack
    PushBottom(st, 7);
    cout << "After pushing 7 to the bottom: ";
    Display(st);
    cout << endl;

    // Reverse the stack
    ReverseStack(st);
    cout << "Reversed stack: ";
    Display(st);
    cout << endl;

    return 0;
}
