/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 const int ninf=-1e9;
int dfs(TreeNode* root,int &ans){
    if(root==NULL)return ninf;
    int val1=dfs(root->left,ans);
    int val2=dfs(root->right,ans);
    ans=max(ans,val1+val2+(root->val));
    ans=max(ans,max({val1,val2,0})+(root->val));
    return max({val1,val2,0})+(root->val); 
}
int Solution::maxPathSum(TreeNode* A) {
    int ans=ninf;
    dfs(A,ans);
    return ans;
}
