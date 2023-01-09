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
    void deleteNode(ListNode* node) {
        if(node->next->next==NULL){
                node->val=node->next->val;
                node->next=NULL;
            }
        while(node->next!=NULL){
            node->val=node->next->val;
            node=node->next;
            if(node->next->next==NULL){
                node->val=node->next->val;
                node->next=NULL;
            }
        }
       // node->val=NULL;
    }
};
