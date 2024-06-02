#include<iostream>
using namespace std;
int size;
int *elements;
class Queue{
    public:
    int capacity;
    int front=0,rear=0;
    Queue(int size1){
        elements=new int(size1);
        capacity=size;
        front=rear=-1;
    }
    void enQueue(int val){
       if(rear==(capacity-1)){
            cout<<"Queue is Full";
            cout<<"\n";
            displayQueue();
       }
        else if(front==-1){
            front++;
        }
        rear++;
        elements[rear]=val;
    }
    int deQueue(){
        int temp=elements[front];
        for(int i=0;i<rear-1;i++){
            elements[i]=elements[i+1];
        }
        rear--;
        if(rear==-2){
            cout<<"\nQueue is Empty";
            return -1;
        }
        cout<<temp;
        return 1;
    }   
    void displayQueue(){
        for(int i=front;i<=rear;i++){
            cout<<elements[i];
            if(i!=rear){
                cout<<",";
            }
        }
    }
    int getFront(){
        if(front==-1){
            return -1;
        }
        else{
            return elements[front];
        }
    }
    int isEmpty(){
        if(front==-1 && rear==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isFull(){
        if(front==0 & rear==(capacity-1)){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main(){
    cin>>size;
    Queue obj(size);
    cout<<obj.getFront();
    cout<<"\n";
    cout<<obj.isFull();
    cout<<"\n";
    cout<<obj.isEmpty();
    cout<<"\n";
    obj.enQueue(2);
    obj.displayQueue();
    cout<<"\n";
    obj.enQueue(4);
    obj.displayQueue();
    cout<<"\n";
    cout<<obj.isFull();
    cout<<"\n";
    cout<<obj.isEmpty();
    cout<<"\n";
    obj.enQueue(6);
    cout<<"\n";
    obj.deQueue();
    cout<<"\n";
    obj.deQueue();
    cout<<"\n";
    obj.deQueue();
    cout<<"\n\n";
    obj.deQueue();
}