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
    //PRO PRO Solution (0.5% better than mine)
    ListNode* removeNthFromEnd_BETTER(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }

    //My Solution
    ListNode* removeNthFromEnd(ListNode* start, int n) {
        long long int c=0;
        ListNode* ptr= start;
        ListNode* prev= start;
        if(start==NULL) return start;

        while(ptr!=NULL){
            c++;
            ptr= ptr->next;
        }

        long long int llsize= c-n;
        long long int s=llsize;
        ptr=start;

        if(s==0 && c==1){
            start=NULL;
            return start;
        }
        else if(s==0){
            start= start->next;
            return start;
        }

        while(ptr->next!=NULL && s>0){
            s--;
            prev=ptr;
            ptr= ptr->next;
        }

        prev->next= ptr->next;

        return start;
    }
};