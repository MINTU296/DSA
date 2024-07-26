#include<bits/stdc++.h>
using namespace std;

void Display(queue<int> &q){
    int s=q.size();
    while(s--){
        cout<<q.front()<<" ";
        int x=q.front();
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void Reverse(queue<int> &q){
    stack<int>st;

    while(!q.empty()){
        int x=q.front();
        st.push(x);
        q.pop();
    }

    while(!st.empty()){
        int x=st.top();
        q.push(x);
        st.pop();
    }
}

void removeATeven(queue<int> &q){
    int n=q.size();
    for(int i=0; i<n; i++){
        if(i%2!=0){
            int x=q.front();
            q.push(x);
        }
        q.pop();
    }
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(4);
    q.push(2);
    q.push(70);
    q.push(0);
    q.push(10);
    q.push(40);

    Display(q);
    // Reverse(q);
    // Display(q);
    removeATeven(q);
    Display(q);
    return 0;
}