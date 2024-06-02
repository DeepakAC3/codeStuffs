#include<iostream>
using namespace std;

void merge(int L[],int R[], int A[], int nL, int nR){
    int i=0;
    int j=0;
    int k=0;
    while(i<nL && j<nR){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nL){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<nR){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[],int n){
    if(n<2) return;
    int mid = n/2;
    int L[mid];
    int R[n-mid];
    for(int i=0;i<mid;i++){
        L[i] = A[i];
    }
    for(int i=mid;i<n;i++){
        R[i-mid] = A[i];
    }
    mergeSort(L,mid);
    mergeSort(R,n-mid);
    merge(L,R,A,mid,n-mid);
}


int main(){

    int arr[]={5,6,2,1};
    mergeSort(arr,4);
    for(auto &c: arr){
        cout<<c;
    }
    return 0;
}