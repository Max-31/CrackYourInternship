class Solution{ 
    Node* rev(Node* node){
        Node* curr= node, *ptr=NULL, *prev= NULL;
        
        while(curr != NULL){
            ptr= curr->next;
            curr->next= prev;
            
            prev= curr;
            curr= ptr;
        }
        
        return prev;
    }
    
    void print(Node* node){
        while(node!=NULL){
            cout<<node->data<<" ";
            node= node->next;
        }
        cout<<endl;
    }
    
public:
    void reorderList(Node* head) {
        //mid
        
        // head= rev(head);
        
        Node*slow=head, *fast= head;
        Node* mhead;
        Node* fhead= head;
        while(fast!=NULL && fast->next != NULL){
            slow= slow->next;
            
            fast= fast->next->next;
        }
        
        mhead= slow->next;
        slow->next= NULL;
        // print(mhead);
        
        mhead= rev(mhead);
        
        // print(mhead);
        head= new Node(-1);
        Node* ptr= head;
        Node* ptr1= fhead, *ptr2= mhead;
        while(ptr1!=NULL && ptr2!=NULL){
            
            ptr->next= ptr1;
            ptr=ptr->next;
            ptr1= ptr1->next;
            
            ptr->next= ptr2;
            ptr=ptr->next;
            ptr2= ptr2->next;
            
        }
        while(ptr1!=NULL){
            ptr->next= ptr1;
            ptr=ptr->next;
            ptr1= ptr1->next;
        }
        while(ptr2!=NULL){
            ptr->next= ptr2;
            ptr=ptr->next;
            ptr2= ptr2->next;
        }
        
        head= head->next;
        
    }
};