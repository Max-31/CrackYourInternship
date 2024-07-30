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
        map<int, int> m;
        ListNode* ptr= head;
        while(ptr!=NULL){
            m[ptr->val]++;
            ptr=ptr->next;
        }

        ListNode* head1= new ListNode(-1);
        ptr= head1;
        for (auto it: m){
            if(it.second == 1){
                ptr->next= new ListNode(it.first);
                ptr=ptr->next;
            }
        }

        head1= head1->next;
        return head1;
    }
};