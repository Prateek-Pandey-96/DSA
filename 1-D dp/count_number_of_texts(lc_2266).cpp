class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<string, int> cache;
    int helper(string temp){
        int n = temp.length();
        int digit = temp[0]-'0';
        string key = to_string(digit)+"_"+to_string(n);
        if(cache.count(key))
            return cache[key];

        vector<long> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = (dp[i] + dp[i-1])%mod;
            if(i>=2)
                dp[i] = (dp[i] + dp[i-2])%mod;
            if(i>=3)
                dp[i] = (dp[i] + dp[i-3])%mod;
            if(i>=4 and (digit == 7 || digit == 9))
                dp[i] = (dp[i] + dp[i-4])%mod;
        }

        return cache[key] = dp[n];
    }
    int countTexts(string pressedKeys) {
        int n = pressedKeys.length();
        string temp;
        temp.push_back(pressedKeys[0]);
        long res = 1;
        for(int i=1; i<n; i++){
            if(pressedKeys[i]==temp.back())
                temp.push_back(pressedKeys[i]);
            else{
                res = (res % mod * helper(temp) % mod)%mod;
                temp.clear();
                temp.push_back(pressedKeys[i]);
            }
        }
        res = (res * helper(temp))%mod;
        return res;
    }
};