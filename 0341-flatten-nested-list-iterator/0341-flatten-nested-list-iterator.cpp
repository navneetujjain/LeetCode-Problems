/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> arr;
    int pointer = 0;
    void flattenList(vector<NestedInteger> &nestedList) {
        for (auto &it : nestedList) {
            if (it.isInteger()) {
                arr.push_back(it.getInteger());
            } else {
                vector<NestedInteger> temp = it.getList();
                flattenList(temp);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);

        /*for(auto it : nestedList){
            if(it.isInteger()) arr.push_back(it.getInteger());

            else{
                vector<int> temp(it.getList());

                for(auto k : temp) arr.push_back(temp);
            }
        }*/
    }
    
    int next() {
        return arr[pointer++];
        
    }
    
    bool hasNext() {
        if(pointer < arr.size()) return 1;

        return 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */