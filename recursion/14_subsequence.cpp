#include<iostream>
#include<vector>
using namespace std;

void subseq(vector<int>& arr, int idx, int k, vector<int> ans, vector<vector<int>>& finalans){
    if(ans.size()==k){
        finalans.push_back(ans);
        return;
    }
    if(idx==arr.size()) return;


    subseq(arr, idx + 1, k, ans, finalans);
    ans.push_back(arr[idx]);
    subseq(arr, idx + 1, k, ans, finalans);
    
}

int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ans;
    int k=3;
    vector<vector<int>>finalans;
    
    subseq(arr, 0, k, ans, finalans);

    for(int i = 0; i < finalans.size(); i++){
        for(int j = 0; j < finalans[i].size(); j++){
            cout << finalans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}