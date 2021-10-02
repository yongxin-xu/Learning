#include <iostream>
#include <unordered_map>
#include <list>

using std::pair;
using std::unordered_map;
using std::list;

class LRUCache {
public:
    LRUCache(int capacity): _cap(capacity) {}

    int get(int key) {
        auto mit = _map.find(key);
        if (mit == _map.end()) { // key not exists
            return -1;
        }
        int value = mit->second->second;
        auto lit = mit->second;
        _cache.erase(lit);
        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
        return value;
    }

    void put(int key, int value) {
        auto mit = _map.find(key);
        if (mit == _map.end()) {
            if (_cap == _cache.size()) { // cache full
                int eraseKey = _cache.back().first;
                _cache.pop_back(); // evict the back
                _map.erase(eraseKey);
            }
        } else {
            auto lit = mit->second;
            _cache.erase(lit);
        }
        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
    }

private:
    int _cap;
    list<pair<int, int> > _cache;
    unordered_map<int, list<pair<int, int> >::iterator> _map;
};