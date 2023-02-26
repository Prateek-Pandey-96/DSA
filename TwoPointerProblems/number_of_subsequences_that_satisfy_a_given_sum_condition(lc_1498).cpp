class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        
        vector<int> pre(n, 1);
        for(int i=1; i<n; i++)
            pre[i] = (pre[i-1]*2) % mod;

        sort(nums.begin(), nums.end());
        int low = 0, high = n-1, res=0;
        while(low <= high){
            int sum = nums[low] + nums[high];
            if(sum > target)
                high--;
            else
            {
                res = (res + pre[high-low])%mod;
                low++;
            }
        }
        
        return res;
    }
};