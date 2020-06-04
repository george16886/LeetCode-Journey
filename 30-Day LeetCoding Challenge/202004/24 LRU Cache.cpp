#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
   private:
    int cap;
    list<pair<int, int>> operationList;
    unordered_map<int, list<pair<int, int>>::iterator> hmap;

   public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!hmap.count(key)) return -1;
        
        auto operation = hmap.find(key)->second;
        operationList.splice(operationList.begin(), operationList, operation);
        return operation->second;
    }

    void put(int key, int value) {
        if (hmap.count(key))
            operationList.erase(hmap.find(key)->second);

        if (operationList.size() == cap) {
            int keyLRU = operationList.rbegin()->first;
            hmap.erase(keyLRU);
            operationList.pop_back();
        }

        operationList.push_front(make_pair(key, value));
        hmap[key] = operationList.begin();
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
    cout << cache->get(4) << endl
         << endl;

    LRUCache cache2 = LRUCache(2 /* capacity */);
    cache2.get(2);
    cout << cache2.get(2) << endl;
    cache2.put(2, 6);
    cache2.get(1);
    cout << cache2.get(1) << endl;
    cache2.put(1, 5);
    cache2.put(1, 2);
    cache2.get(1);
    cout << cache2.get(1) << endl;
    cache2.get(2);
    cout << cache2.get(2) << endl
         << endl;

    LRUCache cache3 = LRUCache(2 /* capacity */);
    cache3.put(2, 1);
    cache3.put(1, 1);
    cache3.put(2, 3);
    cache3.put(4, 1);
    cache3.get(1);
    cout << cache3.get(1) << endl;
    cache3.get(2);
    cout << cache3.get(2) << endl
         << endl;

    return 0;
}
