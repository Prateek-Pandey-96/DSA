class Solution {
public:
    int combinationSum4(vector<int>& nums, int sum) {
        vector<unsigned int> dp(sum+1, 0);
        dp[0] = 1;
        int N = nums.size();
        for(int i=1; i<=sum; i++){
            for(auto num: nums){
                if(i >= num){
                    dp[i] += dp[i-num];
                }
            }
        }
        
        return dp[sum];
    }
};