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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        // ListNode* ans= new ListNode(-1);
        // ListNode* p= ans;
        ListNode* ptr= head;
        // int f=0;

        while(ptr->next!=NULL){
            if(ptr->val == ptr->next->val){
                ptr->next=ptr->next->next;
            }
            else 
                ptr=ptr->next;
        }

        // ans= ans->next;
        return head;
    }
};