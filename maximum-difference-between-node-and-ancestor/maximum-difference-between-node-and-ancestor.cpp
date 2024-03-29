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
    int s=0;
    void test(TreeNode*root,int mx,int mn){
        if(!root)return;
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        s=max(s,mx-mn);
        test(root->left,mx,mn);
        test(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mn=INT_MAX,mx=INT_MIN;
        test(root,mx,mn);
        return s;
    }
};