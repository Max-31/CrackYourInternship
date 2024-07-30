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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1= l1, *ptr2= l2;

        ListNode *head= new ListNode(-1), *ptr= head;

        int c=0;
        while(ptr1!=NULL && ptr2!=NULL){
            int a= ptr1->val;
            int b= ptr2->val;
            
            int ans= a+b+c;

            int digit= ans%10;
            c= ans/10;

            ptr->next= new ListNode(digit);
            ptr= ptr->next;

            ptr1=ptr1->next;
            ptr2=ptr2->next; 

        }

        while(ptr1!=NULL){
            int a= ptr1->val;

            int ans= a+c;

            int digit= ans%10;
            c= ans/10;

            ptr->next= new ListNode(digit);
            ptr= ptr->next;

            ptr1=ptr1->next;
        }

        while(ptr2!=NULL){
            int b= ptr2->val;

            int ans= b+c;

            int digit= ans%10;
            c= ans/10;

            ptr->next= new ListNode(digit);
            ptr= ptr->next;

            ptr2=ptr2->next;
        }

        while(c>0){
            int digit= c%10;
            ptr->next= new ListNode(digit);
            ptr= ptr->next;

            c= c/10;
        }

        head= head->next;
        return head;
    }
};