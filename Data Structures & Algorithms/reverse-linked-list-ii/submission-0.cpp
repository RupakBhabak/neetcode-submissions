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
    ListNode *reverse_list(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = cur->next;

        while (cur)
        {
            cur->next = prev;

            prev = cur;
            cur = next;
            if (cur)
                next = cur->next;
        }

        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        int i = 1;
        ListNode *temp = head;
        ListNode *head1 = nullptr, *head2, *head3; // h1 -> [0, left-1] h2 -> [left, right]

        while (temp)
        {
            if (i == left)
                head2 = temp;

            if (i == right)
            {
                head3 = temp->next;
                temp->next = nullptr;
                break;
            }

            if (i < left)
                head1 = temp;

            temp = temp->next;
            i++;
        }

        head2 = reverse_list(head2);

        if (head1)
            head1->next = head2;

        temp = head2;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = head3;

        if (!head1)
            return head2;
        else
            return head;
    }
};