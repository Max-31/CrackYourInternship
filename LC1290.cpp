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
    ListNode* rev(ListNode* node){
        ListNode *curr= node, *ptr=NULL, *prev= NULL;
        while(curr!=NULL){
            ptr= curr->next;
            curr->next= prev;

            prev= curr;
            curr= ptr;
        }

        return prev;
    }
public:
    int getDecimalValue(ListNode* head) {
        head= rev(head);

        int ans=0;

        int val= 1;
        ListNode* ptr= head;
        while(ptr!=NULL){
            if(ptr->val)
                ans+= val;

            val*=2;
            ptr=ptr->next;
        }

        return ans;
    }
};