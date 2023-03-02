// LC-2170 BHI KARNA HAI

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];
        for(int i=1; i<n; i++)
            prefix_sum[i] = prefix_sum[i-1] + nums[i];

        int mx_len = 0;
        while(j<n){
            long window_sum = prefix_sum[j] - ((i-1)>=0? prefix_sum[i-1]: 0);

            while(i<=j and (long)nums[j]*(j-i+1) - window_sum > k){
                window_sum = window_sum - nums[i];
                i++;
            }
            mx_len = max(mx_len, j-i+1);
            j++;
        }

        return mx_len;
    }
};