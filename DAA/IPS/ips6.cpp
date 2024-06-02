#include<iostream>
using namespace std;

#define n 4

int distan[20][20] = {{0, 22, 26, 30},
   {30, 0, 45, 35},
   {25, 45, 0, 60},
   {30, 35, 40, 0}
};

int dp[16][4];
int visited = (1<<n) - 1;
int tsp(int mark,int pos){
    if(mark==visited){
        return distan[pos][0];
    }
    if(dp[mark][pos]!=-1){
        return dp[mark][pos];
    }
    int ans = 999;
    for(int city = 0;city<n;city++){
        if((mark & (1<<city)) == 0){
            int nans = distan[pos][city] + tsp(mark|(1<<city),city);
            ans = min(ans,nans);
        }
    }
    return dp[mark][pos] = ans;
}

int main(){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<tsp(1,0)<<endl;
    return 0;
}