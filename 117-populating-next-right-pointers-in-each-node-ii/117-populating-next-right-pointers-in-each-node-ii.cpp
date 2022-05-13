/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)return NULL;
        q.push(root);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int n=q.size();
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                top->next= x;
                top=x;
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            top->next=NULL;
        }
        return root;
    }
};