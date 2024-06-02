#include<iostream>
#include<array>
int linearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i] == key){
            return i;
        }
        i++;
    }
    return -1;
}

int main(){
    int n,key;
    std::cin>>n;
    int arr[n];
    for(auto &c: arr){
        std::cin>>c;
    }
    std::cin>>key;
    std::cout<<linearSearch(arr,n,key);
    std::cout<<"hi";
    return 0;
}