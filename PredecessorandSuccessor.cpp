class Solution
{
    void inorder(Node* node, vector<Node*> &ans){
        if(!node) return;
        
        inorder(node->left, ans);
        ans.push_back(node);
        inorder(node->right, ans);
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        pre=NULL;
        suc=NULL;
        
        vector<Node*> ans;
        inorder(root, ans);
        
        int n= ans.size();
        int l=0, h=n-1, m;
        int f=0;
        while(l<=h){
            m= l+(h-l)/2;
            
            if(ans[m]->key == key){
                f=1; break;
            }
            else if(ans[m]->key < key){
                pre= ans[m];
                l= m+1;
            }
            else{
                suc= ans[m];
                h= m-1;
            }
        }
        
        
        if(f==1){
            if(m>0) pre= ans[m-1];
            if(m<n-1) suc= ans[m+1];
        }
        
    }
};