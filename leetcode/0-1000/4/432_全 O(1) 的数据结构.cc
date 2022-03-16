#include "common.h"

class AllOne {
public:
    set<pair<int, string>> s;
    unordered_map<string, int> m;
    AllOne() {

    }
    
    void inc(string key) {
        int count=m[key]++;
        if(count)
            s.erase({count, key});
        s.insert({m[key], key});
    }
    
    void dec(string key) {
        if(m[key]<=0) return;
        int count=m[key]--;
        s.erase({count, key});
        if(m[key])
            s.insert({m[key], key});
    }
    
    string getMaxKey() {
        if(s.empty()) return "";
        return s.rbegin()->second;
    }
    
    string getMinKey() {
        if(s.empty()) return "";
        return s.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
