#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int>lst;
    lst.push_back(2);
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(3);
    lst.push_back(4);

    // display list;
    for(auto ele: lst){
        cout<<ele<<" ";
    }
    cout<<endl;

    // or display;
    list<int> :: iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // deletion of list
    lst.pop_back();
    for(it=lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
}