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
    map<int,int>mp;
    ListNode* test(ListNode*tmp){
        if(!tmp)return tmp;
        if(mp[tmp->val]>1)return test(tmp->next);
        tmp->next=test(tmp->next);
        return tmp;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*tmp=head;
        while(tmp){
            mp[tmp->val]++;
            tmp=tmp->next;
        }
        return test(head);
    }
};