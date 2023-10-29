class Solution {
public:
    int poorPigs(int bkt, int td, int tt) {
        return ceil(log2(bkt)/log2(int(tt/td) + 1));
    }
};