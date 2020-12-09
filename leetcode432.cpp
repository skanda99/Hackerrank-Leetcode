
// problem: "https://leetcode.com/problems/all-oone-data-structure/"

class AllOne {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string, int>keyVal;
    map<int, unordered_set<string>>valKeys;
    
    AllOne() {
        
    }
    
    void deleteKey(int n, string key) {
        valKeys[n].erase(key);
        
        if(valKeys[n].empty()) {
            valKeys.erase(n);
        }
    }
    
    void addKey(int n, string key) {
        if(valKeys.find(n) != valKeys.end()) {
            valKeys[n].insert(key);
        }
        else {
            valKeys[n] = unordered_set<string>();
            valKeys[n].insert(key);
        }
    }
    
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(keyVal.count(key)) {
            int n = keyVal[key];
            keyVal[key]++;
            
            deleteKey(n, key);      // define
            addKey(n+1, key);       // define
        }
        else {
            keyVal[key] = 1;            
            addKey(1, key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(keyVal.count(key)) {
            int n = keyVal[key];
            
            if(n > 1) {
                keyVal[key]--;
                deleteKey(n, key);
                addKey(n-1, key);
            }
            else {
                keyVal.erase(key);
                deleteKey(1, key);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(valKeys.empty()) {
            return "";
        }
        
        return *((valKeys.rbegin()->second).begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(valKeys.empty()) {
            return "";
        }
        return *((valKeys.begin()->second).begin());
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
