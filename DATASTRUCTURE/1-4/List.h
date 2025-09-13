//
// Created by JJ on 2025/9/13.
//

#ifndef ALLC_C___LIST_H
#define ALLC_C___LIST_H

#include <iostream>
#include <vector>
using namespace std;
struct Node{
    Node* next;
    int value;
    Node(int val):value(val),next(nullptr){}
};
class List{
public:
    Node* head;
    List() {
        head = nullptr;
    }
public:
    void InsertBack(Node* n);
    void InsertAfterKth(Node* n, int k);
    void DeleteElement(int k);
    Node* SearchkthNode(int k);
};

#endif //ALLC_C___LIST_H