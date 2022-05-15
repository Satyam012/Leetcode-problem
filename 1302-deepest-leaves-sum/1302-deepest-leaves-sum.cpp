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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(),cur=0;
            while(n--){
                auto top=q.front();
                q.pop();
                cur+=top->val;
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            ans=cur;
        }
        return ans;
    }
};