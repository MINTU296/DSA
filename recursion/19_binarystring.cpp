#include<iostream>
using namespace std;

void BinaryString(int n, string ans, int idx){

    if(n==ans.length()){
        cout<<ans<<endl;
        return;
    }
    BinaryString(n,ans+"0",idx+1);
    if(ans[ans.length()-1]!='1'){
        BinaryString(n,ans+"1",idx+1);
    }
    
}

int main(){
    string s="adfsfsfs";
    BinaryString(3,"",0);
    return 0;
}