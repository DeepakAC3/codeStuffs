#include<iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++) {
key = arr[i];
j = i - 1;


while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}


void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
int binarysearch(int arr[],int k,int low,int high){
    int l=low;
    int h=high;
    int mid=low+((high-low)/2);
    if(k==arr[mid]){
        return mid;
    }
    if(k>arr[mid]){
        return binarysearch(arr,k,mid+1,high);

    }
    else{
        return binarysearch(arr,k,low,mid-1);
    }


}
int linearsearch(int arr[],int s,int k){
    int index;
    for(int i=0;i<s;i++){
        if(arr[i]==k){
            index=i;
            return index;
        }
    }
    return -1;
}

int main(){

    int arr[]={5,2,7,4,8,91,74,47,86,90,40,3,67,86,91,10000,650,430,62,21,90,12,89,60,98,90};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,size);
    cout<<"sorted array:"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"\n";
    clock_t start,end;
    start=clock();
    int d=binarysearch(arr,2,0,4);
    cout<<"2 Found at index:"<<d<<endl;

    end=clock();
    double tt1=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"execution time for binary search:"<<tt1<<endl;
    clock_t start1,end1;
    start1=clock();
    
    cout<<"Found at index"<<linearsearch(arr,size,2);
    end1=clock();
    
    double tt2=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"execution time for linear search:"<<tt2;
    return 0;


}