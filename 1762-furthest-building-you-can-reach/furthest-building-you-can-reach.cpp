#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    using int2=pair<int, int>;
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        // MinHeap (height[i]-height[i-1], i)
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        int i=0, jump=0;
        for(i=1; i<n ; i++){
            jump=heights[i]-heights[i-1];
            if (jump>0) pq.emplace(jump, i); 
            if (pq.size()>ladders){// Keep the largest `ladders' jumps in heap
                bricks-=pq.top().first; // remaining brick
                pq.pop();
            } 
            if  (bricks<0) return i-1;
        }
        return n-1;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();