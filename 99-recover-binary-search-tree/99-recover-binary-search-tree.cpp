/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 4 2 3 1 5
    TreeNode*left=NULL,*right=NULL,*prev=NULL;
    void solve(TreeNode*root){
        if(!root)return;
        solve(root->left);
        if(left==NULL && prev!=NULL && prev->val>root->val)left=prev;
        if(left!=NULL && prev->val>root->val)right=root;
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        int tmp=left->val;
        left->val=right->val;
        right->val=tmp;
    }
};