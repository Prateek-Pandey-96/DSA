class Solution {
public:
    // unordered_map<int, int> cache;
    // int DFS(int n){
    //     if(n==0)
    //         return 0;
    //     if(cache.count(n))
    //         return cache[n];
    //     int root_limit = sqrt(n);
    //     int perfect_squares = INT_MAX;
    //     for(int i=1; i<=root_limit; i++){
    //         int remainder = n - i*i;
    //         perfect_squares = min(perfect_squares, 1 + DFS(remainder));
    //     }

    //     return cache[n]=perfect_squares;
    // }
    // int numSquares(int n) {
    //     cache.clear();
    //     return DFS(n);
    // }
    int numSquares(int n){
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = INT_MAX;
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }

        return dp[n];
    }
};