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
#define notNull() (node!=nullptr)
#define hasNext() (notNull() && node->next != nullptr)
#define hasChild() (node!=nullptr&&node->child != nullptr)
class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        if(head==NULL)
        {
            return head;            
        }

        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->child!=NULL)
            {
                Node* tail=curr->next;
                Node* child=curr->child;
                curr->next=child;
                child->prev=curr;
                curr->child=NULL;
                while(child->next!=NULL)
                {
                    child=child->next;
                }
                child->next=tail;
                if(tail != NULL && tail->next != NULL)
                tail->prev=child;               
            }
            curr=curr->next;
        }

        // Convert to circular linked list
        Node *tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;
        head->prev = tail;

        return head;
    }
};


void printList(Node* head){
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* node = new Node;
    node = head;
    do{
        cout << node->val << " ";
        node = node->next;
    }
    while(node != head->prev);
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