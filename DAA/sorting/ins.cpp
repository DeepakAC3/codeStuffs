#include<iostream>
using namespace std;

void insertionSort(int* arr, int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main(){
    int arr[] = {5,6,2,1};
    insertionSort(arr,4);
    for(auto &c: arr){
        cout<<c;
    }
    return 0;
}