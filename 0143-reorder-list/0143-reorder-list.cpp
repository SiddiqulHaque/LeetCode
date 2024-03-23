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
ListNode* reverse(ListNode* head) {
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    void reorderList(ListNode* head) {
         if(!head || !head->next){
            return;
         }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=head;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode* l1=head;
        ListNode* l2=reverse(slow);
        while(l2){
            ListNode *nextN=l1->next;
            l1->next=l2;
            l1=l2;
            l2=nextN;
        }
    }
};