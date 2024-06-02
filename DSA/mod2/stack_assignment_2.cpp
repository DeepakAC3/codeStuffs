//infix to postfix converter
//By Deepak Pradip

#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *prev;
};

class Stack{
    public:
    Node* top;
    Stack(){
        this->top = nullptr;
    }

    void push(char value){
        Node* newnode = new Node;
        newnode->data = value;
        newnode->prev = this->top;
        this->top = newnode;
    }

    char pop(){
        if(this->top == nullptr){
            return '\0';
        }
        char value = this->top->data;
        Node* temp = this->top;
        this->top = this->top->prev;
        delete temp;
        return value;
    }

    char peek(){
        if(this->top == nullptr){
            return '\0';
        }
        return this->top->data;
    }

    void print(){
        for(Node* temp = top; temp != nullptr; temp=temp->prev){
            cout<<temp->data;
        }
    }

    bool empty(){
        return this->top == nullptr;
    }

    ~Stack(){
        while(this->top != nullptr){
            Node *temp = this->top;
            this->top = this->top->prev;
            delete temp;
        }
    }
};



class infixToPostfix:public Stack{

    public:
    string exp,result;
    Stack A;
    char c;

    int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
    }



    infixToPostfix(string exp) {
    string result = "";
    for(int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if(isalnum(c))
            result += c;
        else if(c == '(')
            A.push('(');
        else if(c == ')') {
            while(!A.empty() && A.peek() != '(') {
                result += A.peek();
                A.pop();
            }
            if(!A.empty() && A.peek() != '('){
                cout<<"Invalid Expression";
                return;
            }
            else
                A.pop();
        }
        else {
            while(!A.empty() && precedence(A.peek()) >= precedence(c)) {
                result += A.peek();
                A.pop();
            }
            A.push(c);
        }
    }
    while(!A.empty()) {
        result += A.peek();
        A.pop();
    }
    cout<<result;
    }

};


int main() {
    string inp;
    getline(cin,inp);
    infixToPostfix A(inp);
    return 0;
}