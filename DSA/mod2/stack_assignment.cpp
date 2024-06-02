//Postfix expression eval
//Deepak Pradip

#include<iostream>
#include<ctype.h>
#include<cmath>
#include<string>
using namespace std;

struct Node{
    float data;
    Node *prev;
};
class Stack{
    private:
    Node* top;
    public:
    Stack(){
        this->top = nullptr;
    }

    void push(float value){
        Node* newnode = new Node;
        newnode->data = value;
        newnode->prev = this->top;
        this->top = newnode;
    }

    float pop(){
        if(this->top == nullptr){
            return -1;
        }
        float value = this->top->data;
        Node* temp = this->top;
        this->top = this->top->prev;
        delete temp;
        return value;
    }

    float peek(){
        if(this->top == nullptr){
            return -1;
        }
        return this->top->data;
    }

    void print(){
        for(Node* temp = top; temp != nullptr; temp=temp->prev){
            cout<<temp->data;
        }
    }

    bool is_empty(){
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

class EvaluatePostFix:public Stack{
    public:
    Stack A;
    string inp;
    float final,a,b;
    EvaluatePostFix(string inp){
        this->inp = inp;
        for(int i=0; i<inp.length(); i++){
        if(isdigit(inp[i])){
            string num="";
            while(isdigit(inp[i])){
                num += inp[i];
                i++;
            }
            A.push(stof(num));
            i--;
        }
        else if(ispunct(inp[i])){
            b = A.pop();
            a = A.pop();
            switch (inp[i])
            {
                case '+':{
                    final = a + b;
                    A.push(final);
                    break;
                }
                case '/':{
                    final = a / b;
                    A.push(final);
                    break;
                    }   
                case '*':{
                    final = a * b;
                    A.push(final);
                    break;
                    }
                case '-':{
                    final = a - b;
                    A.push(final);
                    break;
                    }
                case '^':{
                    final = pow(a, b);
                    A.push(final);
                    break;
                }
            }
        }
        
    }
    A.print();
}
};



int main(){
    string inp;
    getline(cin,inp);
    EvaluatePostFix A(inp);
    return 0;
}