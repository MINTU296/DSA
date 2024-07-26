#include <bits/stdc++.h>
using namespace std;

// pass by value hai
// it display in reverse oder bottom to top
void display(stack<int> st, int size){
    if(st.size()==0) return;
    cout<<st.top()<<" ";
    st.pop();
    display(st,size-1);
}

// pass by refernce...
// it display in reverse oder bottom to top
void Display(stack<int>& st){
    if(st.size()==0) return;
    int x=st.top();
    cout<<x<<" ";
    st.pop();
    Display(st); // call 
    st.push(x); // kam
}

// printing bottom to top
void displayBottomToTop(stack<int> &st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    displayBottomToTop(st);
    st.push(x);
    cout<<st.top()<<" "; 
}

int main(){
    stack<int>st;
    stack<int>temp1;
    stack<int>temp2;
    st.push(10);  //10 bottom
    st.push(20); //20
    st.push(30); //30
    st.push(40); //49 top
    displayBottomToTop(st);
    cout<<endl;
}