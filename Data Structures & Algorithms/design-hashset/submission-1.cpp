class MyHashSet {
private:
    const int CAPACITY = 10000;
    int *container;

    int hash_func(int key) {
        return (key + (key / 10) + (key % 10)) % CAPACITY;
    }

public:
    MyHashSet() {
        container = new int[CAPACITY];
        fill(container, container + CAPACITY, -1);
    }
    
    void add(int key) {
        if (!contains(key)) {
            container[hash_func(key)] = key;
        }
    }
    
    void remove(int key) {
        if (contains(key)) {
            container[hash_func(key)] = -1;
        }
    }
    
    bool contains(int key) {
        return container[hash_func(key)] == key;
    }
};
