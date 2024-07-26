#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(7);
    s.insert(3);
    s.insert(9);
    s.insert(0);
    s.insert(8);

    for(int ele : s ){
        cout<<ele<<" ";
    }

    cout<<endl;
    
    // finding the element which exist or not
    int tar=7;
    if(s.find(tar)!=s.end()){
        cout<<"target exist"<<endl;
    }
    else{
        cout<<"not exist";
    }
}