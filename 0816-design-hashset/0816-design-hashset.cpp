class MyHashSet {
public:
    unordered_set<int> stt;
    MyHashSet() {
        
    }
    
    void add(int key) {
        stt.insert(key);
    }
    
    void remove(int key) {
        if(stt.find(key) != stt.end()) stt.erase(key);
    }
    
    bool contains(int key) {
        if(stt.find(key) != stt.end()) return true;

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */