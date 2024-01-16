class RandomizedSet {
public:
    unordered_set<int> set;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) != set.end()) return false;

        set.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(set.find(val) != set.end()){
            set.erase(set.find(val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = set.begin();
        int random = 0;
        if(set.size() != 0) random = rand() % set.size();
        advance(it, random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */