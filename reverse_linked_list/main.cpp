#include <iostream>

using namespace std;

struct ListNode {
    ListNode* next;
    int value;

    ListNode(int x): value(x), next(nullptr)
    {

    }
    ListNode(int x, ListNode* node): value(x), next(node)
    {

    }
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

