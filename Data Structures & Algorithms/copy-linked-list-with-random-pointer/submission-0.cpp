/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        Node *temp1 = head;
        Node *prev = nullptr;
        Node *newHead = nullptr;
        int i = 0;

        unordered_map<Node *, int> m1; // For original list. map->(address, index)
        unordered_map<int, Node *> m2; // For deep copied list. map->(index, address)

        while (temp1)
        {
            Node *newNode = new Node(temp1->val);

            // Mapping of original
            m1[temp1] = i;

            // Mapping of copied
            m2[i] = newNode;

            if (!prev)
            {
                newHead = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }

            temp1 = temp1->next;
            i++;
        }

        prev->next = nullptr;

        temp1 = head;          // pointer for original
        Node *temp2 = newHead; // pointer for copied

        while (temp1)
        {
            if (!temp1->random)
                temp2->random = nullptr;
            else
                temp2->random = m2[m1[temp1->random]];

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};
