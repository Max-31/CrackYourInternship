// This function should return head to the DLL
class Solution {
    void preorder(Node* node, vector<int>& trav){
        if(!node) return;


        preorder(node->left, trav);
        trav.push_back(node->data);
        preorder(node->right, trav);
    }
  public:
    Node* bToDLL(Node* root) {
        if(!root) return root;
        
        vector<int> trav;
        preorder(root, trav);
        
        Node* ans= new Node(trav[0]), *ptr= ans, *prev=NULL;
        
        for(int i=1; i<trav.size(); i++){
            ptr->left= prev;
            ptr->right= new Node(trav[i]);
            
            prev= ptr;
            ptr=ptr->right;
        }
        ptr->left= prev;
        return ans;
    }
};