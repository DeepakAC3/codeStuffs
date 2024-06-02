#include<iostream>
using namespace std;

int maxProfit(int prices[],int length){
    if (length<=0) return 0;

    int maxprofit = 0;

    for(int i=1;i<=length;i++){
        int currentProfit = prices[i] + maxProfit(prices,length-i);
        if(currentProfit>maxprofit){
            maxprofit = currentProfit;
        }
    }
    return maxprofit;
}

int main(){
    int prices[] = {0,1,5,8,9,10,17,17,20};
    int length = 8;
    int result = maxProfit(prices,length);
    cout<<result;
    return 0;
}