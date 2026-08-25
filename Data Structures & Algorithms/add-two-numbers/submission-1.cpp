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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int curSum = 0, carry = 0;

        ListNode *t1 = l1, *t2 = l2;
        ListNode *sumNode = nullptr, *newHead = nullptr;

        while (t1 && t2)
        {
            curSum = t1->val + t2->val + carry;
            carry = 0;

            if (curSum > 9)
            {
                carry = curSum / 10;
                curSum = curSum % 10;
            }

            if (!newHead)
            {
                newHead = new ListNode(curSum);
                sumNode = newHead;
            }
            else
            {
                sumNode->next = new ListNode(curSum);
                sumNode = sumNode->next;
            }

            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1)
        {
            curSum = t1->val + carry;
            carry = 0;

            if (curSum > 9)
            {
                carry = curSum / 10;
                curSum = curSum % 10;
            }

            sumNode->next = new ListNode(curSum);
            sumNode = sumNode->next;

            t1 = t1->next;
        }

        while (t2)
        {
            curSum = t2->val + carry;
            carry = 0;

            if (curSum > 9)
            {
                carry = curSum / 10;
                curSum = curSum % 10;
            }

            sumNode->next = new ListNode(curSum);
            sumNode = sumNode->next;

            t2 = t2->next;
        }

        if (carry)
        {
            sumNode->next = new ListNode(carry);
            sumNode = sumNode->next;
        }

        sumNode->next = nullptr;

        return newHead;
    }
};
