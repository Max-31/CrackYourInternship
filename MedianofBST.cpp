void inorder(struct Node *node, vector<int>&ans){
    if(!node) return;
    
    inorder(node->left, ans);
    ans.push_back(node->data);
    inorder(node->right, ans);
    
}

float findMedian(struct Node *root){
    vector<int> ans;
    inorder(root, ans);
    
    if(ans.size()%2){
        return ans[ans.size()/2];
    }
    else{
        return 1.0*(ans[ans.size()/2] + ans[(ans.size()-1)/2])/2 ; 
    }
}