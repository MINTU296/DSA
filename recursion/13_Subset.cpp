#include<iostream>
using namespace std;

void subset(string s, int idx, string ans){
    if(idx==s.length()){
        cout<<ans<<endl;
        return;
    }
    subset(s, idx+1, ans+s[idx]);
    subset(s, idx+1, ans);
    
}

void subset1(string original, string output){

    if(original==""){
        cout<<output<<endl;
        return;
    }
    subset1(original.substr(1), output+original[0]);
    subset1(original.substr(1), output);
}

int main(){
    // subset("abc",0,"");
    subset1("abc","");
    return 0;
}