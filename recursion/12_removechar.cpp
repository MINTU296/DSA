#include<iostream>
#include <string>
using namespace std;

void removechar(string s, int i, string output){
    if(s.length()==i){
        cout<<output;
    }
    else if(s[i]=='a'){
        removechar(s,i+1,output);
    }
    else{
        removechar(s,i+1,output+s[i]);
    }
}

int main(){
    string s="Ragav gargh";
    removechar(s,0,"");
    // cout<<ans;
    return 0;
}