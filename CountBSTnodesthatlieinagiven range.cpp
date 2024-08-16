class Solution{
    // inorder(){
    //     if(!node) return 0;
        
    //     inorder(nod-)
    // }
public:
    int getCount(Node *node, int l, int h){
        if(!node) return 0;
        
        int leftie, rightie=0;
        if(l>node->data) leftie=0;
        else leftie= getCount(node->left, l, h);
        
        
        if(h<node->data) rightie=0;
        else rightie= getCount(node->right, l, h);
        
        if(l<=node->data && node->data<=h) return 1+leftie+rightie;
        return leftie+rightie;
    }
};