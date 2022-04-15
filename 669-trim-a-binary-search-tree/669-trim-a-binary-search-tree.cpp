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
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        if(!root)return root;
        if(root->val>=l&&root->val<=h){
            root->left=trimBST(root->left,l,h);
            root->right=trimBST(root->right,l,h);
        }
        else if(root->val>h)root=trimBST(root->left,l,h);
        else root=trimBST(root->right,l,h);  
        return root;
    }
};