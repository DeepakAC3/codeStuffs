#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    void insertAtEnd(int data){
        Node* newnode = new Node;
        newnode->data = data;
        if(head==nullptr){
            head = newnode;
        }
        else{
            for(Node* ptr = head;ptr!=nullptr;ptr=ptr->next){
                if(ptr->next==nullptr){
                    ptr->next=newnode;
                    newnode->next=nullptr;
                }
            }
        }
    }
    void print(){
            for(Node* ptr=head;ptr!=nullptr;ptr=ptr->next){
                cout<<ptr->data;
            }
    }
    void delete_list(){
        for(Node* ptr=head;ptr!=nullptr;ptr=ptr->next){
            delete ptr;
        }
    }
    int count(){
        int counter=1;
        for(Node*ptr = head;ptr!=nullptr;ptr=ptr->next){
            counter++;
        }
        return counter;
    }
    void delete_node(int pos){
        int cnt = count();
        int i=1;
        for(Node*ptr = head;ptr!=nullptr;ptr=ptr->next){
            i++;
            if(i==pos){
                ptr->next = ptr->next->next;
                delete ptr->next;
            }
        }
    }
};

int main(){
    LinkedList A;
    A.insertAtEnd(2);
    A.insertAtEnd(3);
    A.insertAtEnd(5);
    A.insertAtEnd(4);
    A.print();
    return 0;
}