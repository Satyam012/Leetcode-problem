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
    int ans=0;
    int sumRootToLeaf(TreeNode* &root,int s=0) {
        if(!root)return ans;
        if(!root->left && !root->right){
            ans+=(s+root->val);
            return ans;
        }
        // root->val=2*s+root->val;
        sumRootToLeaf(root->left,(s+root->val)*2);
        sumRootToLeaf(root->right,(s+root->val)*2);
        return ans;
    }
};