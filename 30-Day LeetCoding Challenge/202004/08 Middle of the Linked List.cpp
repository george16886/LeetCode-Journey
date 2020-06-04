#include <stddef.h>

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;

        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        // printf(" with count = %d", count);

        for (int i = 0; i < count / 2; i++) {
            tmp = tmp->next;
        }

        return tmp;
    }
};

// Function to print a linked list
void printList(ListNode* node) {
    std::cout << "[";

    while (node) {
        std::cout << node->val;
        if (node->next != NULL)
            std::cout << ", ";
        node = node->next;
    }

    std::cout << "]";
}

int main(int argc, char** argv) {
    Solution solution;
    ListNode* output;

    ListNode* input1 = new ListNode(1);
    ListNode* input2 = new ListNode(2);
    ListNode* input3 = new ListNode(3);
    ListNode* input4 = new ListNode(4);
    ListNode* input5 = new ListNode(5);
    input1->next = input2;
    input2->next = input3;
    input3->next = input4;
    input4->next = input5;

    std::cout << "Example 1:" << std::endl;
    printf("Input: ");
    printList(input1);

    output = solution.middleNode(input1);
    printf("\nOutput: ");
    printList(output);
    printf("\n");

    ListNode* input6 = new ListNode(6);
    input5->next = input6;
    std::cout << std::endl;
    std::cout << "Example 2:" << std::endl;
    printf("Input: ");
    printList(input1);

    output = solution.middleNode(input1);
    printf("\nOutput: ");
    printList(output);
    printf("\n");

    return 0;
}