#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
};

class Stack{
    private:
    Node* top;
    public:
    Stack(){
        this->top = nullptr;
    }
    void push(int value){
        Node* newnode = new Node;
        newnode->data = value;
        newnode->prev = this->top;
        this->top = newnode;
    }
    int pop(){
        if(this->top == nullptr){
            return -1;
        }
        int value = this->top->data;
        Node* temp = this->top;
        this->top = this->top->prev;
        delete temp;
        return value;
        
    }
    int peek(){
        return this->top->data;
    }
    bool is_empty(){
        return this->top == nullptr;
    }
    ~Stack(){
        while(this->top != nullptr){
            Node* temp = this->top;
            this->top = this->top->prev;
            delete temp;
        }
    }
    
};

int main(){
    return 0;
}