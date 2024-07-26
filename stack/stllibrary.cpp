#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int>st;
    stack<int>temp;
    st.push(10);  //10
    st.push(20); //20
    st.push(30); //30
    st.push(49); //49

    while(st.size()>0){
        // printing top to bottom
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        // printing in bottom to top
        cout<<temp.top()<<" "; 
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
    

}