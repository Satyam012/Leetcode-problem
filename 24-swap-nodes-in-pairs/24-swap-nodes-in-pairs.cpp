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
    ListNode* swapPairs(ListNode* head) {
        ListNode*prev=new ListNode(0),*newHead=prev;
        prev->next=head;
        while(prev->next && prev->next->next){
            ListNode*node1=prev->next;
            ListNode*node2=node1->next;
            node1->next=node2->next;
            node2->next=node1;
            prev->next=node2;
            prev=prev->next->next;
        }
        return newHead->next;
    }
};