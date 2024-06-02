//Polynomials using linked lists
//created by Deepak Pradip
#include<iostream>
#include<math.h>
using namespace std;
class PolynomialTerm {
public:
    int coefficient;
    int exponent;

    PolynomialTerm(int coeff = 0, int exp = 0) : coefficient(coeff), exponent(exp) {}
};

class LinkedListNode {
public:
    PolynomialTerm term;
    LinkedListNode* next;
    LinkedListNode(PolynomialTerm t) : term(t), next(nullptr) {}
};

class Polynomial {
private:
    LinkedListNode* head;

public:
    Polynomial() : head(nullptr) {}
    
    // Insert a term into the linked list in sorted order of exponents.
    void read(int coeff, int exp) {
        PolynomialTerm newTerm(coeff, exp);
        LinkedListNode* newNode = new LinkedListNode(newTerm);

        if (head == nullptr || head->term.exponent < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            LinkedListNode* current = head;
            while (current->next != nullptr && current->next->term.exponent >= exp) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Add two polynomials.
    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        LinkedListNode* node1 = head;
        LinkedListNode* node2 = other.head;

        while (node1 && node2) {
            if (node1->term.exponent == node2->term.exponent) {
                result.read(node1->term.coefficient + node2->term.coefficient, node1->term.exponent);
                node1 = node1->next;
                node2 = node2->next;
            } else if (node1->term.exponent > node2->term.exponent) {
                result.read(node1->term.coefficient, node1->term.exponent);
                node1 = node1->next;
            } else {
                result.read(node2->term.coefficient, node2->term.exponent);
                node2 = node2->next;
            }
        }

        while (node1) {
            result.read(node1->term.coefficient, node1->term.exponent);
            node1 = node1->next;
        }

        while (node2) {
            result.read(node2->term.coefficient, node2->term.exponent);
            node2 = node2->next;
        }

        return result;
    }

    // Display the polynomial.
    void display(){
        LinkedListNode* current = head;
        while (current) {
            cout << current->term.coefficient << "," << current->term.exponent;
            current = current->next;
            if (current) {
                cout << "->";
            }
        }
        cout << endl;
    }
};


int main(){
    int terms1,terms2=0;
    int coeff,pow=0;
    Polynomial poly1,poly2,poly3;
    cout<<"Enter the no. of terms for poly1:";
    cin>>terms1;
    for(int i=0;i<terms1;i++){
        cout<<"Enter term"<<i+1<<": "<<endl;
        cout<<"Enter coeff: ";
        cin>>coeff;
        cout<<endl<<"Enter power: ";
        cin>>pow;
        poly1.read(coeff,pow);
        cout<<endl;
    }
    cout<<"Enter the no. of terms for poly2:";
    cin>>terms2;
    for(int i=0;i<terms2;i++){
        cout<<"Enter term"<<i+1<<":"<<endl;
        cout<<"Enter coeff: ";
        cin>>coeff;
        cout<<endl<<"Enter power: ";
        cin>>pow;
        poly2.read(coeff,pow);
        cout<<endl;
    }
    poly3 = poly1.add(poly2);
    poly3.display();
    return 0;
}