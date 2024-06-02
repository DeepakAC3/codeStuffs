#include<bits/stdc++.h>
#define swap(a,b) a^=b; b^=a; a^=b
int* bubblesort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int flag = 0;
        for(int k =0;k<n-i-1;k++){
            if(A[k]<A[k+1]){
                swap(A[k],A[k+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    return A;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(auto &c: arr){
        scanf("%d",&c);
    }
    bubblesort(arr,n);
    for(auto &c:arr){
        printf("%d ",c);
    }
    return 0;
}