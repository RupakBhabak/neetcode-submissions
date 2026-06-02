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
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        ListNode *slow = head; // slow pointer
        ListNode *fast = head; // fast pointer

        while (slow && fast)
        {
            slow = slow->next; // move slow pointer one step

            if (fast->next)
                fast = fast->next->next; // move fast pointer two step
            else
                return false;

            if (slow == fast && (slow && fast))
                return true;
        }

        return false;
    }
};
