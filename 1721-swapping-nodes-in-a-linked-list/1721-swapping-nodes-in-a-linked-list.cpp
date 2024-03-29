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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)return head;
        ListNode*h1=head,*h2=head,*tmp=head;
        while(--k){
            tmp=tmp->next;
        }
        h1=tmp;
        while(tmp->next){
            tmp=tmp->next;
            h2=h2->next;
        }
        swap(h1->val,h2->val);
        return head;
    }
};