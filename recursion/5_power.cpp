#include<iostream>
using namespace std;

int power(int base, int pow){
    if(pow==0){
        return 1;
    }
    int ans=base*power(base,pow-1);
    return ans;
}

// with time complexity.....

int powr(int base,int pow){
    if(pow==0){
        return 1;
    }
    int ans=powr(base,pow/2);

    if(pow%2==0){
        return ans*ans;
    }
    else if(pow%2!=0){
        return ans*ans*base;
    }
    
}

int main(){
    // cout<<power(5,2);
    cout<<powr(5,1);
    return 0;
}