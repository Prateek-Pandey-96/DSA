class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        /*Robber doesnt steal from house 1*/
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        for(int i=3;i<n;i++)
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);    

        int ans = dp[n-1];
        /*Robber steals from house 1*/
        dp.clear();
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n-1;i++)
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        
        return max(ans, dp[n-2]);
    }
};