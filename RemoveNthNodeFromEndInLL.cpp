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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head,*slow=head;int num=n;
        if(n==1){
            if(fast->next==NULL){
                return nullptr;
            }
            while(fast->next->next!=NULL){
                
                fast=fast->next;
            }
            fast->next=NULL;
            return head;
        }
        while((n--)){
            fast=fast->next;
        }
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==head and fast==NULL){
            head=head->next;
        }
        else slow->next=slow->next->next;
        return head;
    }
};
