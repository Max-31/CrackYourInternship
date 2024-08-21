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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* hless= new ListNode(-1), *hhigh= new ListNode(-1);
        ListNode* ptr= head, *pless= hless, *phigh= hhigh;

        while(ptr){
            if(ptr->val <x){
                pless->next= new ListNode(ptr->val);
                // pless->next= ptr;
                pless= pless->next;
            }
            else{
                phigh->next= new ListNode(ptr->val);
                // phigh->next= ptr;
                phigh= phigh->next;
            }

            ptr= ptr->next;
        }

        if(!hless->next){
            return hhigh->next;
        }
        hless= hless->next;
        hhigh= hhigh->next;

        pless->next= hhigh;

        return hless;
    }
};