#include<iostream>
using namespace std;

int main(){
    int stages = 4, min;
    int n = 8;
    int cost[] = {0,0,0,0,0,0,0,0,0};
    int path[9];
    int d[9];

    int C[9][9] = {
       //0 1 2 3 4 5 6 7 8
        {0,0,0,0,0,0,0,0,0},
        {0,0,2,1,3,0,0,0,0},
        {0,0,0,0,0,2,3,0,0},
        {0,0,0,0,0,6,7,0,0},
        {0,0,0,0,0,6,8,9,0},
        {0,0,0,0,0,0,0,0,6},
        {0,0,0,0,0,0,0,0,4},
        {0,0,0,0,0,0,0,0,5},
        {0,0,0,0,0,0,0,0,0}
    };
    for(int i=stages-1;i>=1;i--){
        min = 32767;
        for(int k=i+1;k<=n;k++ ){
            if(C[i][k] != 0 && C[i][k] + cost[k] < min){
                min = C[i][k]+cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }
    path[1] = 1;
    path[stages] = n;
    for(int i=2;i<=stages;i++) path[i] = path[d[i-1]];

    for(int i=1;i<=stages;i++){
        if (path[i] == 1 || path[i] == 2 || path[i] == 6 || path[i] == 8) {
            cout<<path[i]<<" ";
        }
    }

    return 0;
}