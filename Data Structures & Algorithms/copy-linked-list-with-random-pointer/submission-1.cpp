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
        unordered_map<Node *, Node *> m; // map->(original node address, copy node address)
        m[nullptr] = nullptr;

        Node *cur = head;

        while (cur)
        {
            Node *copy = new Node(cur->val);
            m[cur] = copy;
            cur = cur->next;
        }

        cur = head;

        while (cur)
        {
            Node *copy = m[cur];
            copy->next = m[cur->next];
            copy->random = m[cur->random];
            cur = cur->next;
        }

        return m[head];
    }
};
