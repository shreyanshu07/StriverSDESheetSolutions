class Solution
{ // Runtime: 45 ms, faster than 92.53% of C++ online submissions for Intersection of Two Linked Lists.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *t1 = headA, *t2 = headB;   //traversal node 1 and traversal node 2
        while (t1 != t2) // Traverse till nodes are not common
        {
            t1 = t1->next; // Advance the list 1
            t2 = t2->next; // Advance the list 2
            if (t1 == t2)  // If same, return the node
                return t1;
            if (!t1)        // If t1 == NULL, list A < List B,
                t1 = headB; // Assign the other List
            if (!t2)        // If t1 == NULL, list A > List B
                t2 = headA; // Assign the other List
            /*
            This List assignment, will ensure that lists of different sizes, reach a point from where
            Both the lists have equal nodes to traverse till the end.
            Now t1 == t2 statement will break the loop when both the nodes point NULL
            Or when both the nodes point to the intersection point
            */
        }
        return t1; // if t1 == t2, initially, return t1
    }
};
