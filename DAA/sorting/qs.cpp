#include<iostream>
using namespace std;

int partition(int* arr, int l, int r){
    int pi = arr[l];
    while(true){
        while(arr[l]<pi) l++;
        while(arr[r]>pi) r--;

        if(l>=r) return r;

        swap(arr[l],arr[r]);

        l++;
        r--;
    }
}

void quicksort(int* arr,int l,int r){
    if(l<r){
        int q = partition(arr,l,r);
        quicksort(arr,l,q);
        quicksort(arr,q+1,r);
    }
}

int main(){
    int arr[] = {5,6,1,2};
    quicksort(arr,0,4-1);
    for(auto &c:arr){
        cout<<c;
    }
    return 0;
}