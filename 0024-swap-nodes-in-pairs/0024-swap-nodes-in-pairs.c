struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL && curr->next != NULL) {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;
        prev->next = next;

        prev = curr;
        curr = curr->next;
    }

    return dummy->next;
}