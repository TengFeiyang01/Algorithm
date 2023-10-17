#include <iostream>
#include "myList.h"

void List::init() {
    head = new Node;
    head->next = nullptr;
}

void List::insert(int data) {
    Node *cur = new Node;
    cur->d = data;

    cur->next = head->next;
    head->next = cur;
}

Node *List::search(int x) {
    Node *p = head;
    p = p->next;
    while (p) {
        if (p->d == x) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void List::traverse() {
    if (head == nullptr) return;
    Node *cur = head;
    cur = cur->next;
    while (cur) {
        std::cout << cur->d << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void List::destory() {
    Node *t;
    while (head) {
        t = head;
        head = head->next;
        delete t;
    }
}
