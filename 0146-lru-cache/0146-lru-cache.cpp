class LRUCache {
    list<int>dll;
    map<int, pair< list<int>::iterator, int>>mp;
    int n;

    void makeRecentUsed(int key)
    {
        dll.erase(mp[key].first); // find and delete the node at address
        dll.push_front(key); // push it into front to make it most recent used
        mp[key].first = dll.begin(); // update address of node in map
    }

public:
    LRUCache(int capacity) : n(capacity) {}

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        makeRecentUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentUsed(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0)
        {
            int keyToDel = dll.back();
            mp.erase(keyToDel);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */