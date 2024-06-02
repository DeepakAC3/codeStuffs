#include<iostream>
using namespace std;

class Stack{
    private:
    int *data;
    int capacity;
    int top;

    public:
    Stack(int capacity){
        this->data = new int[capacity];
        this->top = -1;
        this->capacity = capacity;
    }

    void push(int value){
        if(this->top == this->capacity-1){
            return;
        }

        this->top++;
        this->data[this->top]=value;
    }

    int pop(){
        if(this->top == -1){
            return -1;
        }
        int value = this->data[this->top];
        this->top--;
        return value;
    }

    int peek() {
        if(this->top == -1){
            return -1;
        }
        return this->data[this->top];
    }

    bool is_empty(){
        return this->top == -1;
    }

    bool is_full() {
        return this->top == this->capacity -1;
    }

    ~Stack(){
        delete[] this->data;
    }

};

int main(){
    Stack A(2);
    A.push(2);
    A.push(3);
    cout<<A.pop()<<endl;
    cout<<A.pop()<<endl;
    cout<<A.is_empty()<<endl;
    return 0;
}