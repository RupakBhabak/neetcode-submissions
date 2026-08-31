class Node
{
public:
    int key, val;
    Node *next, *prev;

    Node()
    {
        key = val = 0;
        prev = next = nullptr;
    }

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        prev = next = nullptr;
    }
};

class LRUCache
{
private:
    Node *left, *right;               // left -> least recently used, right -> most recently used
    unordered_map<int, Node *> cache; // map -> (key, corresp. node)
    int capacity, size;

    // Insert Node n right before 'right'
    void insert(Node *n)
    {
        Node *p = right->prev;
        p->next = n;
        n->prev = p;
        n->next = right;
        right->prev = n;
    }

    // Unlink Node n from the list
    void remove(Node *n)
    {
        Node *prev = n->prev;
        Node *next = n->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity)
    {
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;

        this->capacity = capacity;
        size = 0;
    }

    ~LRUCache()
    {
        Node *cur = left;
        while (cur)
        {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *n = cache[key];
            remove(n);
            insert(n);
            return n->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            // Key exists: update value, unlink old node, delete it
            remove(cache[key]);
            delete cache[key];
        }
        else
        {
            size++;
        }

        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (size > capacity)
        {
            // Evict LRU: capture key before deleting the node
            Node *lru = left->next;
            int lruKey = lru->key;
            remove(lru);
            delete lru;
            cache.erase(lruKey);
            size--;
        }
    }
};