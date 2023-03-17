class Solution {
public:
    // int num;
    // unordered_map<int, int> cache;
    // int DFS(int n){
        
    //     if(n<=1)
    //         return 1;
        
    //     if(cache.count(n))
    //         return cache[n];
        
    //     int max_product = (num==n)?0:n;
    //     for(int i=1; i<n; i++){
    //         max_product = max(max_product, DFS(i)*DFS(n-i));
    //     }
        
    //     return cache[n]=max_product;
    // }
    // int integerBreak(int n) {
    //     num = n;
    //     return DFS(n);
    // }
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);

        for(int i=2; i<=n; i++){
            int max_product = (i == n)?0:i;
            for(int j=1; j<i; j++){
                max_product = max(max_product, dp[j]*dp[i-j]);
            }
            dp[i] = max_product;
        }

        return dp[n];
    }
};