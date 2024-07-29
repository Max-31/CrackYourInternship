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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *p1= head1;
        ListNode *p2= head2;

        ListNode *head= new ListNode(-200);
        ListNode *ptr= head;

        while(p1!=NULL && p2!=NULL){
            if(p1->val < p2->val){
                ptr->next= new ListNode(p1->val);
                ptr=ptr->next;

                p1= p1->next;
            }
            else if(p1->val >= p2->val){
                ptr->next= new ListNode(p2->val);
                ptr=ptr->next;

                p2= p2->next;
            }
        }
        while(p1!=NULL){
            ptr->next= new ListNode(p1->val);
            ptr=ptr->next;

            p1= p1->next;
        }
        while(p2!=NULL){
            ptr->next= new ListNode(p2->val);
            ptr=ptr->next;

            p2= p2->next;
        }

        head= head->next;
        return head;
    }
};