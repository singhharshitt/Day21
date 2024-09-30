#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

bool detectCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleStart = nullptr;
    int index = 0;

    while (temp->next != nullptr) {
        if (index == pos) {
            cycleStart = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleStart;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    int pos = 1;
    createCycle(head, pos);

    if (detectCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
