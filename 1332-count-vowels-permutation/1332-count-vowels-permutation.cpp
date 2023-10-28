class Solution {
public:
    
    int MOD=1e9+7;

    long long int f(int n, int i, char c, vector<vector<int>> &dp, unordered_map<char, int> &mpp){
        
        if(i==n) return 1;
        
        long long count = 0;
        
        if(dp[mpp[c]][i]!=-1) return dp[mpp[c]][i]%MOD;
        
        if(c=='a'){
		// after a only e is allowed
            count += f(n, i+1, 'e', dp, mpp);
        }
        
        if(c=='e'){
		// after e only a and i are allowed
            count += f(n, i+1, 'a', dp, mpp);
            count += f(n, i+1, 'i', dp, mpp);
        }
        if(c=='i'){
		// after i everthing except i is allowed
            count += f(n, i+1, 'a', dp, mpp);
            count += f(n, i+1, 'e', dp, mpp);
            count += f(n, i+1, 'o', dp, mpp);
            count += f(n, i+1, 'u', dp, mpp);
        }
        if(c=='o'){
		// after o only i and u are allowed
            count += f(n, i+1, 'i', dp, mpp);
            count += f(n, i+1, 'u', dp, mpp);
        }
        
        if(c=='u'){
		// after u only a is allowed
            count += f(n, i+1, 'a', dp, mpp);
        }
        
        return dp[mpp[c]][i] = count%MOD;
        
    }
    
    int countVowelPermutation(int n) {
        
		// map to convert char to int for using in dp vector for memoization purpose
        unordered_map<char, int> mpp;
        mpp['a'] = 0;
        mpp['e'] = 1;
        mpp['i'] = 2;
        mpp['o'] = 3;
        mpp['u'] = 4;
        
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
		
				//call for each starting from each vowel after that for changing the character values our recursive call will take care of

        long long count = f(n, 1, 'a', dp, mpp) + f(n, 1, 'e', dp, mpp) + f(n, 1, 'i', dp, mpp) + f(n, 1, 'o', dp, mpp) + f(n, 1, 'u', dp, mpp); 
        
        return count%MOD;
        
    }
};