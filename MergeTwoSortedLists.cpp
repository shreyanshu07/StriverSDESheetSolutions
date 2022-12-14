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
    ListNode *list3 = new ListNode;
    ListNode *ptr = list3;
    //ptr=list3;
    void push(int n){
        ListNode *new_node = new ListNode;
        new_node->val = n;
        new_node->next = NULL;
        ptr->next=new_node;
        ptr = new_node;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        while(list1 != NULL or list2 != NULL){
            //ListNode *new_node = new ListNode;
            if(list1 == NULL){
                push(list2->val);
                list2=list2->next;
            }
            else if(list2 == NULL){
                push(list1->val);
                list1=list1->next;
            }
            else{
                if(list1->val > list2->val){
                    push(list2->val);
                    list2=list2->next;
                }
                else{
                    push(list1->val);
                    list1=list1->next;
                }
            }
        }
        list3=list3->next;
        return list3;
    }
};
