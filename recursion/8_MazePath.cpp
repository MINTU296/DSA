#include<iostream>
#include<string>
using namespace std;

int MazePath(int R, int D){
    // BASE CASE
    if(R==1 && D==1){
        return 1;
    }
    else if(R<1 || D<1){
        return 0;
    }
    int RighWays=MazePath(R-1,D);
    int DownWays=MazePath(R,D-1);
    return RighWays+DownWays;
}

// Printing Path
void MazePath1(int R, int D, string s){
    // BASE CASE
    if(R==1 && D==1){
        cout<<s<<endl;
        return;
    }
    else if(R<1 || D<1){
        return;
    }
    MazePath1(R-1,D,s+'R'); // going right
    MazePath1(R,D-1,s+'D'); // going DOWN
    
    
}

int main(){
    MazePath1(3,3,"");
    return 0;
}