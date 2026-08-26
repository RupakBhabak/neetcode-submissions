#include <cstddef>

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        val = NULL;
        next = nullptr;
    }

    Node(int _val)
    {
        val = _val;
        next = nullptr;
    }
};

class MyCircularQueue
{
private:
    Node *front, *rear;
    int size, capacity;

public:
    MyCircularQueue(int k)
    {
        front = new Node();
        rear = front;

        Node *temp = front;

        for (int i = 1; i < k; i++)
        {
            temp->next = new Node();
            temp = temp->next;
        }

        temp->next = front;

        capacity = k;
        size = 0;
    }

    bool enQueue(int value)
    {
        if (size >= capacity)
            return false;

        if (size > 0)
            rear = rear->next;

        rear->val = value;

        size++;
        return true;
    }

    bool deQueue()
    {
        if (size <= 0)
            return false;

        if (size > 1)
            front = front->next;

        size--;
        return true;
    }

    int Front()
    {
        if (size == 0)
            return -1;
        else
            return front->val;
    }

    int Rear()
    {
        if (size == 0)
            return -1;
        else
            return rear->val;
    }

    bool isEmpty()
    {
        return size <= 0;
    }

    bool isFull()
    {
        return size >= capacity;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */