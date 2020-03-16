#include <stddef.h>
#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* cur = ans;
        int c = 0;

        while (l1 || l2) {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;
            int sum = a + b + c;
            c = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }

        if (c) cur->next = new ListNode(1);

        return ans->next;
    }
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* ans = addABC(l1, l2, c);

        return ans;
    }

    ListNode* addABC(ListNode* l1, ListNode* l2, int& c) {
        int a = (l1) ? l1->val : 0;
        int b = (l2) ? l2->val : 0;
        int sum = a + b + c;
        ListNode* ans = new ListNode(sum % 10);

        if (!l1 && !l2)
            if (c)
                return ans;
            else
                return NULL;

        l1 = (l1) ? l1->next : l1;
        l2 = (l2) ? l2->next : l2;
        c = sum / 10;
        ans->next = addABC(l1, l2, c);

        return ans;
    }
};

// Function to print a linked list
void printList(ListNode* node) {
    std::cout << "(";
    while (node) {
        std::cout << node->val;
        if (node->next != NULL)
            std::cout << " -> ";
        node = node->next;
    }
    std::cout << ")";
}

int main(int argc, char** argv) {
    printf("Input: ");

    ListNode* a1 = new ListNode(2);
    ListNode* a2 = new ListNode(4);
    ListNode* a3 = new ListNode(3);
    a1->next = a2;
    a2->next = a3;
    printList(a1);

    printf(" + ");

    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(4);
    b1->next = b2;
    b2->next = b3;
    printList(b1);

    Solution solution;
    ListNode* ans = solution.addTwoNumbers(a1, b1);

    printf("\nOutput: ");
    printList(ans);
    printf("\n");
    return 0;
}