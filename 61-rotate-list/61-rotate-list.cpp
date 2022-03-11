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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode*tmp=new ListNode(0),*test=head;
        int cnt=0;
        while(test){
            test=test->next;
            cnt++;
        }
        k%=cnt;
        if(k==0||head==NULL)return head;
        tmp->next=head;
        ListNode*l1=tmp,*l2=tmp;
        while(l2->next&&k--){
            l2=l2->next;
        }
        while(l2->next){
            l2=l2->next;
            l1=l1->next;
        }
        ListNode*head1=l1->next;
        l1->next=NULL;
        l2->next=head;
        return head1;
    }
};