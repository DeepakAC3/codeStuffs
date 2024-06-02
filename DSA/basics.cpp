#include<bits/stdc++.h>
class Queue{
    public:
    int size, front, rear;
    int *elements;
    
    Queue(int n){
        elements = new int[n];
        for(int i=0;i<n;i++){
            elements[i]=0;
        }
        size=n;front=-1;rear=-1;
    }

    void enQueue(int val){
        if(front == -1){
            front = 0;
        }
        rear++;
        elements[rear] = val;
    }

    int deQueue(){
        int temp = elements[front];
        front++;
        return temp;
    }

    int isFull(){
        if(rear == size-1) return 1;
        return 0;
    }

    int isEmpty(){
        if(front == rear == -1) return 1;
        return 0;
    }

    int fr(){
        return elements[front];
    }

    void deleteQueue(){
        delete elements;
        front = rear = -1;
        size = 0;
    }

    void display(){
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++){
            std::cout<<elements[i]<<" ";
        }
        std::cout<<"\n";
    }
};


int main(){
    int size = 10;
    Queue Q(size);
    Q.enQueue(10);
    Q.display();
    Q.enQueue(20);
    Q.display();
    Q.enQueue(50);
    Q.display();
    Q.enQueue(5);
    Q.display();
    Q.deQueue();
    Q.display();
    std::cout<<"\n"<<Q.fr()<<"\n";
    Q.deQueue();
    Q.display();
    std::cout<<"\n"<<Q.isEmpty()<<"\n";
    Q.deleteQueue();
    Q.display();
    return 0;
}