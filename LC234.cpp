class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;

        //finding mid
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;

        prev = slow, slow = slow->next, prev->next = NULL;

        //reversing mid
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;

        fast = head, slow = prev;

        //comparing 2halves
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }
};