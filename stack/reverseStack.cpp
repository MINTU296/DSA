#include <bits/stdc++.h>
using namespace std;

// stack should pass by value if we pass by reference 
// original stack become empty
void print(stack<int> st){
    while(st.size()>0){
        // printing top to bottom
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int>st;
    stack<int>temp1;
    stack<int>temp2;
    st.push(10);  //10
    st.push(20); //20
    st.push(30); //30
    st.push(40); //49

    while(st.size()>0){
        // printing top to bottom
        cout<<st.top()<<" ";
        temp1.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp1.size()>0){
        temp2.push(temp1.top());
        temp1.pop();
    }

    while(temp2.size()>0){
        st.push(temp2.top());
        temp2.pop();
    }
    // now printing the stack
    print(st);
    
}