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
    TreeNode* test(TreeNode*root){
        if(!root)return root;
        test(root->right);
        s+=root->val;
        root->val=s;
        test(root->left);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        s=0;
        return test(root);
    }
};