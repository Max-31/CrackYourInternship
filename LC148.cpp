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
    ListNode* joinbreak(ListNode* leftlist, ListNode* rightlist){
        ListNode* nlist= new ListNode(-1);
        ListNode* ptr= nlist;
        ListNode* ptrleft= leftlist;
        ListNode* ptrright= rightlist;

        while(ptrleft && ptrright){
            if(ptrleft->val <= ptrright->val){
                ptr->next= new ListNode(ptrleft->val);
                ptrleft= ptrleft->next;
            }
            else{
                ptr->next= new ListNode(ptrright->val);
                ptrright= ptrright->next;
            }
            ptr= ptr->next;
        }
        while(ptrleft){
            ptr->next= new ListNode(ptrleft->val);
            ptrleft= ptrleft->next;
            ptr= ptr->next;
        }
        while(ptrright){
            ptr->next= new ListNode(ptrright->val);
            ptrright= ptrright->next;
            ptr= ptr->next;
        }

        nlist= nlist->next;
        return nlist;
    }
    
public:
    ListNode* sortList(ListNode* node) {
        if(!node || !node->next){
            return node;
        }

        //find mid
        ListNode* slow= node, *fast= node->next;
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* secondhalf= slow->next;
        slow->next= NULL;

        //1st half
        ListNode* left= sortList(node);
        //2nd half
        ListNode* right= sortList(secondhalf);

        //merge
        return joinbreak(left, right);
    }
};