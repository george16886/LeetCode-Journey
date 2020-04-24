#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
   private:
    int cap;
    unordered_map<int, int> hmap;
    list<int> keyList;

   public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        keyList.push_front(keyList.back());
        keyList.pop_back();
        return (hmap[key]) ? hmap[key] : -1;
    }

    void put(int key, int value) {
        if (keyList.size() == cap) {
            keyList.pop_back();
            keyList.push_front(key);
        } else {
            keyList.push_front(key);
        }
        
        hmap[key] = value;

        cout << "list front " << keyList.front() << endl;
        cout << "list back " << keyList.back() << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char** argv) {
    LRUCache* cache = new LRUCache(2 /* capacity */);

    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);  // returns 1
    cout << cache->get(1) << endl;
    cache->put(3, 3);  // evicts key 2
    cache->get(2);     // returns -1 (not found)
    cout << cache->get(2) << endl;
    cache->put(4, 4);  // evicts key 1
    cache->get(1);     // returns -1 (not found)
    cout << cache->get(1) << endl;
    cache->get(3);  // returns 3
    cout << cache->get(3) << endl;
    cache->get(4);  // returns 4
    cout << cache->get(4) << endl;

    return 0;
}
