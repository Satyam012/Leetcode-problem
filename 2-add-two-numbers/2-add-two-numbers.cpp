/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*root=new ListNode(0),*tmp;
        tmp=root;
        int c=0,s=0;
        while(l1||l2){
            s=0;
            if(l1!=NULL){
                s=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                s+=l2->val;
                l2=l2->next;
            }
            s+=c;
            c=s>9?1:0;
            s%=10;
            tmp->next=new ListNode(s);
            tmp=tmp->next;
            cout<<tmp->val<<" ";
        }
        if(c)tmp->next=new ListNode(1);
        return root->next;
    }
};