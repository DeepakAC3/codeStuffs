#include <iostream>
using namespace std;

// struct Node {
//   int val;
//   Node* prev;
//   Node* next;
//   Node* child;
// };

class Solution{
    public:
Node* flatten(Node* head) {
  if (head == nullptr) return head;
  Node* node = head;
  while (node != head->prev) {
    if (node->child != nullptr) {
      Node* temp = node->next;
      node->next = node->child;
      node->child->prev = node;
      node->child = nullptr;
      Node* tail = node->next;
      while (tail->next != node->next) {
        tail = tail->next;
      }
      tail->next = temp;
      temp->prev = tail;
    }
    node = node->next;
  }
  return head;
}

// void printFlattenedList(Node* head) {
//   Node* node = flatten(head);
//   cout << node->val << " ";
//   node = node->next;
//   while (node != head) {
//     cout << node->val << " ";
//     node = node->next;
//   }
// }
};

