class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), dp(n, 1);
        int mx_len = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] and lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                    dp[i] = dp[j];
                }else if(nums[i]>nums[j] and lis[i]==lis[j]+1){
                    dp[i] += dp[j];
                }
            }
            mx_len = max(mx_len, lis[i]);
        }
        
        int total = 0;
        for(int i=0; i<n; i++)
            if(lis[i]==mx_len)
                total += dp[i];
        
        return total;
    }