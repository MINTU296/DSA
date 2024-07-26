#include<bits/stdc++.h>
using namespace std;

int checkPal(string s, int i, int j){
    if(i>j) return 1;
    if(s[i]!=s[j]) return false;
    else return checkPal(s,i+1,j-1);
    
}

int main(){
    string s= "aaxaa";
    int i=0;
    int j=s.size()-1;
    cout<<checkPal(s,i,j);
    return 0;
}