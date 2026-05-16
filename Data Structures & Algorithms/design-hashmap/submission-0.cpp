class MyHashMap {
private:
    const int CAPACITY = 10000;
    vector<pair<int, int>> container;

    int hash_func(int key) {
        return (key + (key / 10) + (key % 10)) % CAPACITY;
    }

public:
    MyHashMap() {
        for (int i = 0; i < CAPACITY; i++) {
            container.push_back(make_pair(-1, -1));
        }
    }
    
    void put(int key, int value) {
        container[hash_func(key)] = make_pair(key, value);
    }
    
    int get(int key) {
        pair<int, int> p = container[hash_func(key)];

        if (p.first == key) {
            return p.second;
        } else {
            return -1;
        }
    }
    
    void remove(int key) {
        container[hash_func(key)] = make_pair(-1, -1);
    }
};
