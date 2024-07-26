#include <iostream>
#include <vector>
using namespace std;

// Defining a custom stack class using std::vector
class Stack {
public:
    vector<int> arr;
    // Push function to add an element to the stack
    void push(int val) {
        arr.push_back(val);
    }
    // Pop function to remove the top element from the stack
    void pop() {
        if (!arr.empty()) {
            arr.pop_back();
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    // Top function to get the top element of the stack
    int top() {
        if (!arr.empty()) {
            return arr.back();
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 if the stack is empty
        }
    }

    // Size function to get the current size of the stack
    int size() {
        return arr.size();
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    cout << "Stack size: " << st.size() << endl; // Display the stack size
    cout << "Top element: " << st.top() << endl; // Display the top element
    st.pop();
    cout << "Stack size after pop: " << st.size() << endl; // Display the stack size after a pop
    cout << "Top element after pop: " << st.top() << endl; // Display the top element after a pop

    return 0;
}
