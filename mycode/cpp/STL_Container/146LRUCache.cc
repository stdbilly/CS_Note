#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>
using std::unordered_map;
using std::list;
using std::pair;
using std::cout;
using std::endl;

class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity){}

    int get(int key) {
        if(_cache.find(key) == _cache.end()) {
            return -1;
        } else {
            _used.splice(_used.begin(), _used, _cache[key]);
            _cache[key] = _used.begin();
            return _used.begin()->second;
        }
    }

    void put(int key, int value) {
        if(_cache.find(key) != _cache.end()) {
            _used.splice(_used.begin(), _used, _cache[key]);
            _used.begin()->second = value;
            _cache[key] = _used.begin();
        } else {
            if(_cache.size() == _capacity) {
                int deleteKey = _used.back().first;
                _cache.erase(deleteKey);
                _used.pop_back();
            }
            _used.push_front({key, value});
            _cache[key] = _used.begin();
        }

    }
private:
    typedef list<pair<int,int> > pairList;
    pairList _used;
    int _capacity;
    unordered_map<int, pairList::iterator> _cache;
};

void test1() {
    LRUCache* cache = new LRUCache( 2 /* capacity */  );

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns -1 (not found)
    cout << cache->get(4) << endl;       // returns -1 (not found)
}

int main() {
    test1();
    return 0;
}

