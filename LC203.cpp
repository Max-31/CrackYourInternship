/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        if(head->next==NULL && head->val==val) return NULL;
        if(head->next==NULL) return head;

        ListNode *ptr=head->next, *prev= head;


        while(ptr!=NULL){
            if(ptr->val == val){
                prev->next= ptr->next;
            }
            else{
                prev= ptr;
            }
            ptr=ptr->next;
        }

        if(head->val == val) head= head->next;

        return head;
    }
};