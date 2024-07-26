#include<bits/stdc++.h>
using namespace std;

void SubArray(vector<int>& arr, int idx, vector<int> ans, vector<vector<int>>& finalans){
    if(idx==arr.size()){
        finalans.push_back(ans);
        return;
    }
    SubArray(arr,idx+1,ans,finalans);
    if(ans.size()==0 ||arr[idx-1]==ans[ans.size()-1] ){
        ans.push_back(arr[idx]);
        SubArray(arr,idx+1,ans,finalans);
    }
}

int main(){
    vector<int>arr={1,2,3,4};
    vector<int>ans;
    int idx=0;
    vector<vector<int>>finalans;

    SubArray(arr,idx,ans,finalans);

    for(int i=0; i<finalans.size();i++){
        for(int j=0;j<finalans[i].size();j++){
            cout<<finalans[i][j];
        }
        cout<<endl;
    }
    return 0;
}