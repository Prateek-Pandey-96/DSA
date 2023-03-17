class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for(auto num: nums)
            count[num]++;
        vector<int> modified_nums;
        for(auto [k, v]: count)
            modified_nums.push_back(k);
        
        int n = modified_nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = modified_nums[0] * count[modified_nums[0]];

        for(int i=2; i<=n; i++){
            if(modified_nums[i-1]-1 == modified_nums[i-2]){
                dp[i] = max(dp[i-1], dp[i-2] + modified_nums[i-1]*count[modified_nums[i-1]]);
            }else{
                dp[i] = dp[i-1] + modified_nums[i-1]*count[modified_nums[i-1]];
            }
        }

        return dp[n];
    }
};