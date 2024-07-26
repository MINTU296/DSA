#include<bits/stdc++.h>
using namespace std;

int Check_BalanceBracket(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char current = s[i];
        if (current == '(') {
            st.push(current);
        } else {
            if (st.empty()) return 0;
            char top = st.top();
            if (current == ')' && top == '(') {
                st.pop();
            } else {
                return 0;
            }
        }
    }
    return st.empty() ? 1 : 0;
}

int main() {
    string s = "()(((()))";
    cout << Check_BalanceBracket(s);
    return 0;
}
