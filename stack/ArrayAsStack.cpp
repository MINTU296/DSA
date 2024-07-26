#include <bits/stdc++.h>
using namespace std;

// Defining a custom stack class
class Stack {
public:
    int arr[100];
    int idx = -1;
    // Push function to add an element to the stack
    void push(int val) {
        if (idx < 99) { // Check to avoid overflow
            idx++;
            arr[idx] = val;
        } else {
            cout << "Stack overflow" << endl;
            return;
        }
    }
    // Pop function to remove the top element from the stack
    void pop() {
        if (idx >= 0) { // Check to avoid underflow
            idx--;
        } else {
            cout << "Stack underflow" << endl;
            return;
        }
    }
    // Top function to get the top element of the stack
    int top() {
        if (idx >= 0) {
            return arr[idx];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 if the stack is empty
        }
    }
    // Size function to get the current size of the stack
    int size() {
        return idx + 1;
    }
};

int main() {
    Stack st; // st is object
    st.push(1);
    st.push(2);
    cout << "Stack size: " << st.size() << endl; // Display the stack size
    cout << "Top element: " << st.top() << endl; // Display the top element
    st.pop();
    cout << "Stack size after pop: " << st.size() << endl; // Display the stack size after a pop
    cout << "Top element after pop: " << st.top() << endl; // Display the top element after a pop

    return 0;
}
