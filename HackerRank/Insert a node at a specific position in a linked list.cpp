#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position) {
    if (llist == nullptr) {
        return new SinglyLinkedListNode(data);
    }
    auto *head = llist;
    while (head != nullptr && position > 1) {
        head = head->next;
        position--;
    }
    auto *next = head->next;
    head->next = new SinglyLinkedListNode(data);
    head->next->next = next;
    return llist;
}

