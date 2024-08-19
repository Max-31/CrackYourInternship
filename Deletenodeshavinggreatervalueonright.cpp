struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
    Node* rev(Node* head){
        if(!head) return NULL;
        
        Node* prev=NULL, *curr= head, *ptr;
        while(curr){
            ptr= curr->next;
            curr->next= prev;
            
            prev= curr;
            curr=ptr;
        }
        
        return prev;
    }
  public:
    Node *compute(Node *head) {
        Node * nhead= rev(head);
        
        Node*prev= nhead, *ptr= prev->next;
        while(ptr){
            if(ptr->data < prev->data){
                prev->next= ptr->next;
                ptr=ptr->next;
            }
            else{
                prev= ptr;
                ptr= ptr->next;
            }
        }
        
        head= rev(nhead);
        return head;
    }
};