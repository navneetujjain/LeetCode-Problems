class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<long long , long long> mp;
        mp[0] = 1;
        int xor_sum = 0;
        for(auto ch : word)
        {
            int shift = ch - 'a';
            xor_sum ^= (1 << shift);
            if(mp.count(xor_sum))
                ans += mp[xor_sum];
            mp[xor_sum]++;
            for(int i = 0; i < 10; i++)
            {
                int temp_shift = (xor_sum ^ (1 << i));
                if(mp.count(temp_shift))
                    ans += mp[temp_shift];
            }
        }
        return ans;
    }
};