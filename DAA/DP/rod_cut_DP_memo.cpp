#include<iostream>
#include<climits>
using namespace std;
#define size 8

int max(int a,int b) {return a>b ?a:b;}

int cutRod(int price[],int index,int n,int dp[size+1][size+1]){

    if(index==0) return n * price[0];

    if(dp[index][n]!= -1){
        return dp[index][n];
    }

    int not_cut = cutRod(price, index - 1, n, dp);
    int cut = INT_MIN;
    int rod_length = index + 1;
    if(rod_length<=n){
        cut = price[index] + cutRod(price,index,n - rod_length, dp);
    }
    return dp[index][n] = max(not_cut,cut);

}
int main(){
    int arr[] = {1,5,8,9,10,17,17,20};
    int dp[size+1][size+1];

    for(int i=0;i<size;i++){
        for(int j=0;j<size+1;j++){
            dp[i][j]=-1;
        }
    }
    cout<<cutRod(arr,size-1,size,dp);
    return 0;
}