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
    ListNode* merge( ListNode* a , ListNode* b){
    ListNode* result = NULL; 
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
 
    if (a->val <= b->val) { 
        result = a; 
        result->next = merge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = merge(a, b->next); 
    } 
    return (result); 
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast =head->next;
        while(fast && fast->next){        
            fast= fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;    
        slow->next = NULL;                 
        return merge(sortList(head) , sortList(headb));        
    }
};