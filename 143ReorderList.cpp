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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* ptr= head;

        while(ptr!=NULL){
            v.push_back(ptr->val);
            ptr=ptr->next;
        }

        long long int n= v.size();
        long long int i= 0, j= n-1;

        ptr= head;
        while(i<j){
            ptr->val= v[i];
            ptr=ptr->next;
            ptr->val= v[j];
            ptr=ptr->next;

            i++; j--;
        }
        if(n%2==1){
            //v[n/2]
            ptr->val= v[n/2];
        }
    }
};