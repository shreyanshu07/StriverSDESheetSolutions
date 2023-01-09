/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        bool loop = false;
        while(fastPtr!=NULL and fastPtr->next!=NULL){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
            if(slowPtr==fastPtr){
                loop = true;
                break;
            }
        }
        if(loop){
            slowPtr=head;
            while(slowPtr!=fastPtr){
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return fastPtr;
        }
        else return NULL;
    }
};
