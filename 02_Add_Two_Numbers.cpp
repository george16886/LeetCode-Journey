/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first = l1->val + l2->val;
        int carry = 0;
        if (first > 9) {
                first = first - 10;
                carry = 1;
            } 
        ListNode* firstNode = new ListNode(first);
        ListNode* ans = firstNode;
        while (l1->next != 0 || l2->next != 0) {
            if (l1->next != 0) l1 = l1->next;
            else l1->val = 0;
            if (l2->next != 0) l2 = l2->next; 
            else l2->val = 0;
            ListNode* newNode = new ListNode(l1->val + l2-> val + carry);
            firstNode->next = newNode;
            carry = 0;
            if (newNode->val > 9) {
                newNode->val = newNode->val - 10;
                carry = 1;
            } 
            firstNode = firstNode->next;
        }
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            firstNode->next = newNode;
            firstNode = firstNode->next;
        }
        return ans;
    }
};
