#include <List.h>
#include <iostream>
#include <vector>
using namespace std;
void List::InsertBack(Node* n){
    if (n==nullptr) return;
    if (head==nullptr) {
        Node* newnode=new Node(n->value);
        head=newnode;
        return;
    }
    Node* backnode=head;
    while (backnode->next!=nullptr) {
        backnode=backnode->next;
    }
    Node* newnode=new Node(n->value);
    backnode->next=newnode;
}
void List::InsertAfterKth(Node* n, int k){
    if (n==nullptr||k<0) return;
    if (k==0) {
        Node* newnode=new Node(n->value);
        newnode->next=head;
        head=newnode;
        return;
    }
    Node* knode=head;
    for (int i=1;i<k;i++) {
        if (knode==nullptr) return;
        knode=knode->next;
    }
    if (knode==nullptr) return;
    Node* newnode=new Node(n->value);
    newnode->next=knode->next;
    knode->next=newnode;
}
void List::DeleteElement(int k){
    if (head==nullptr||k<1) return;
    if (k == 1) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    Node* knode=head;
    for (int i=1;i<k-1;i++) {
        if (knode==nullptr) return;
        knode=knode->next;
    }
    if (knode==nullptr||knode->next==nullptr) return;
    Node* fnode=knode->next;
    knode->next=fnode->next;
    delete fnode;
}
Node* List::SearchkthNode(int k){
    if (head==nullptr||k <1) return nullptr;
    Node* knode=head;
    for (int i=1;i<k;i++) {
        if (knode==nullptr) return nullptr;
        knode=knode->next;
    }
    return knode;
}