/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        int x = 0;
        int y = 0;

        if (l1 != NULL)
            x = l1->val;

        if (l2 != NULL)
            y = l2->val;

        int total = x + y + carry;

        carry = total / 10;
        int digit = total % 10;

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    return dummy->next;
}