#include<iostream>
#include<string>
using namespace std;

struct Item{
    int profit, weight;
    string name;
};

void insertionSort(Item arr[],int N){
    for(int i=1;i<N;i++){
        Item key = arr[i];
        int j = i-1;
        while(j>=0 && (double)arr[j].profit / arr[j].weight < (double)key.profit / key.weight){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

int fractionalKnapsack(int W, Item arr[], int N){
    insertionSort(arr,N);
    double final = 0.0;
    int count = 0;
    string arr1[N];
    for(int i=0;i<N;i++){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            final += arr[i].profit;
            arr1[count] += arr[i].name;
            count++;
        }
        else{
            final += arr[i].profit * ((double) W / (double) arr[i].weight);
            arr1[count] += arr[i].name;
            count++;
            break;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<arr1[i]<<endl;
    }
    return final;
}

int main(){
    int W = 300;
    Item arr[] = {{60,10},{120,30},{100,20}};
    int N = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<N;i++){
        arr[i].name = "ob" + to_string(i);
    }
    cout<<fractionalKnapsack(W,arr,N);
    return 0;
}