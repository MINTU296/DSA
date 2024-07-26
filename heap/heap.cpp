#include<bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[1000];
    int size=0;
    
    void inster(int val){
        size = 1+size;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2; // parent found at

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            } 
            else{
                return;
            }

        }
    }

    void deletetion(){

        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        // put last element in root ;
        arr[1]=arr[size];
        // remove the last elemetn
        size--;

        // making the heap max if not
        int i=1;
        while(i<size){
            int left_idx=2*i; // left child at this postion
            int right_idx=2*i+1; // right child at this postion

            if(left_idx < size && arr[i] < arr[left_idx]){
                swap(arr[i], arr[left_idx]);
                i=left_idx;
            }
            else if(right_idx < size && arr[i] < arr[right_idx]){
                swap(arr[i], arr[right_idx]);
                i=right_idx;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    heap h; // object
    h.inster(10);
    h.inster(5);
    h.inster(30);
    h.inster(40);
    h.inster(50);
    h.inster(50);
    h.inster(60);
    h.deletetion();
    h.deletetion();
    h.deletetion();
    h.deletetion();
    h.deletetion();

    h.print();
}