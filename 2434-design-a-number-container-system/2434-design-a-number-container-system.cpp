class NumberContainers {
public:
    unordered_map<int, int> mpp;
    unordered_map<int, set<int>> msp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp[index] == 0){
            mpp[index] = number;
            msp[number].insert(index);
        }
        else{
            msp[mpp[index]].erase(index);
            msp[number].insert(index);
            mpp[index] = number;
        }
    }
    
    int find(int number) {
        if(msp[number].empty()) return -1;

        else return *msp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */