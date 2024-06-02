#include<iostream>
#include<vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


#define notNull() (node!=nullptr)
#define hasNext() (notNull() && node->next != nullptr)
#define hasChild() (node!=nullptr&&node->child != nullptr)

class Solution {
public:
    Node* flatten(Node* head) {
        // create a dummy node to store the head of the circular linked list
        Node* dummy = new Node();
        dummy->next = dummy;
        dummy->prev = dummy;
        Node* node = head;
        while(1){
            while(hasNext()){
                if(hasChild()){
                    // insert the node's next to the circular linked list
                    dummy->prev->next = node->next;
                    node->next->prev = dummy->prev;
                    dummy->prev = node->next;
                    node->next = node->child;
                    node->child->prev = node;
                }
                node->child = nullptr;
                node = node->next;
            }
            if(hasChild()){
               // insert the node's child to the circular linked list
               dummy->prev->next = node->child;
               node->child->prev = dummy->prev;
               dummy->prev = node->child;
               node->child = nullptr;
            }
            if(dummy->next != dummy){
                // get the next node from the circular linked list
                dummy->next->prev = node;
                node=(node->next=dummy->next);
                // remove the next node from the circular linked list
                dummy->next = dummy->next->next;
                dummy->next->prev = dummy;
            } else break;
        }
        return head;
    }
};


void printList(Node* head){
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* node = head;
    do{
        cout << node->val << " ";
        node = node->next;
    }
    while(node != nullptr);
    cout << endl;
}

Node* createList(vector<int> values){
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int val : values){
        Node* node = new Node();
        node->val = val;
        if(head == nullptr){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}
void connectChild(Node* parent, Node* child){
    parent->child = child;
}

int main(){
    Solution sol;
    Node* head1 = createList({1,2,3,4,5,6});
    connectChild(head1->next, createList({7,8,9,10}));
    connectChild(head1->next->child->next, createList({11,12}));
    connectChild(head1->next->child->next->child->next, createList({13,14}));
    Node* head2 = createList({1,2});
    connectChild(head2, createList({3}));
    Node* head3 = nullptr;
    cout << "Original list 1:" << endl;
    printList(head1);
    cout << "Original list 2:" << endl;
    printList(head2);
    cout << "Original list 3:" << endl;
    printList(head3);
    cout << "Flattened list 1:" << endl;
    printList(sol.flatten(head1));
    cout << "Flattened list 2:" << endl;
    printList(sol.flatten(head2));
    cout << "Flattened list 3:" << endl;
    printList(sol.flatten(head3));
    return 0;
}