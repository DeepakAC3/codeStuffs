#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

void convertToCircular(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
    head->prev = current;
}

#define notNull() (node!=nullptr)
#define hasNext() (notNull() && node->next != nullptr)
#define hasChild() (node!=nullptr&&node->child != nullptr)
class Solution {
public:
    Node* flatten(Node* head) {
    if (head == nullptr) return head;
    Node* node = head;
    while (node != nullptr) {
        if (node->child != nullptr) {
            Node* next = node->next;
            node->next = node->child;
            node->child->prev = node;
            node->child = nullptr;
            Node* temp = node->next;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = next;
            if (next != nullptr) next->prev = temp;
        }
        node = node->next;
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
    }while(node != head);
    cout << endl;
}

Node* createList(vector<int> values){
    Node* head = nullptr;
    //Node* tail = new Node;
    Node* prev = nullptr;
    Node* next = nullptr;
    for(int val : values){
        if(head==nullptr){
            head = new Node;
            head->next= head;
            head->prev = head;
            prev=next=head;
            head->val = val;
        }
        else{
            Node* newnode = new Node;
            newnode->val = val;
            newnode->prev = prev;
            newnode->next = next;
            prev->next = newnode;
            next->prev = newnode;
            prev = newnode;
            
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
    convertToCircular(head1);
    Node* head2 = createList({1,2});
    connectChild(head2, createList({3}));
    convertToCircular(head2);
    Node* head3 = nullptr;
    convertToCircular(head3);
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