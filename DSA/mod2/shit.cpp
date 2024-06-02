
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

#include<stack>

#define notNull() (node!=nullptr)
#define hasNext() (notNull() && node->next != nullptr)
#define hasChild() (node!=nullptr&&node->child != nullptr)

class Solution {
public:
    Node* flatten(Node* head) {
        std::stack<Node*> stk;
        Node* node = head;
        while(1){
            while(hasNext()){
                if(hasChild()){
                    stk.push(node->next);
                    node->next = node->child;
                    node->child->prev = node;
                }
                node->child = nullptr;
                node = node->next;
            }
            if(hasChild()){
               stk.push(node->child);
               node->child = nullptr; 
            }
            if(!stk.empty()){
                stk.top()->prev = node;
                node=(node->next=stk.top());
                stk.pop();
            } else break;
        }
        return head;
    }
};