#include<bits/stdc++.h>

#define swap(a, b) a^=b, b^=a, a^=b

int partition(int* arr, int l, int r) {
    int pi = arr[l];
    while (true) {
        while (arr[l] < pi) l++;
        while (arr[r] > pi) r--;

        if (l >= r) return r;

        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void quicksort(int* arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quicksort(arr, l, q);
        quicksort(arr, q + 1, r);
    }
}

int BinarySearch(int arr[],int key,int low,int high){
    if(low>high){
        return -1;
    }
    int mid;
    mid = (high+low-1)/2;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid]>key){
        return BinarySearch(arr,key,low,mid-1);
    }
    else{
        return BinarySearch(arr,key,mid+1,high);
    }
}


int main(){
    int arr[] = {5,1,2,10,20,30};
    quicksort(arr,0,5);
    for(int i:arr){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl<<BinarySearch(arr,20,0,5);

    return 0;
}


