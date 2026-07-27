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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr && list2 != nullptr)
            return list2;
        else if (list1 != nullptr && list2 == nullptr)
            return list1;

        ListNode *temp = nullptr;
        ListNode *head; // new head

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                if (!temp)
                {
                    head = new ListNode(list1->val);
                    temp = head;
                }
                else
                {
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                }

                list1 = list1->next;
            }
            else
            {
                if (!temp)
                {
                    head = new ListNode(list2->val);
                    temp = head;
                }
                else
                {
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }

                list2 = list2->next;
            }
        }

        if (list1)
        {
            temp->next = list1;
        }

        if (list2)
        {
            temp->next = list2;
        }

        return head;
    }
};
