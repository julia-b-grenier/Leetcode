#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    // Store the next node in a temporary variable.
    ListNode *nextNode = node->next;

    // Copy data of the next node to the current node.
    node->val = nextNode->val;

    // Change the next pointer of the current node to the next pointer of the next node.
    node->next = nextNode->next;
    nextNode->next = nullptr;
    delete(nextNode);
}

int main() {
    
}