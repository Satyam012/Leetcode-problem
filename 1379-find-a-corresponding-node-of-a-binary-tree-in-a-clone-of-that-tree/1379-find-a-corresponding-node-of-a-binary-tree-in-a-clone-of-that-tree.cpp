/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int k;
    TreeNode* test(TreeNode*root){
        if(!root)return NULL;
        if(root->val==k)return root;
        TreeNode*ll=test(root->left);
        if(ll!=NULL)return ll;
        TreeNode*rr=test(root->right);
        if(rr!=NULL)return rr;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        k=target->val;
        return test(cloned);
    }
};