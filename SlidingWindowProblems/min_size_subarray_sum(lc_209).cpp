class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), min_len = INT_MAX;
        int sum = 0, i = 0, j = 0;

        while(j<n){
            sum += nums[j];
            
            while(sum >= target){
                min_len = min(min_len, j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return min_len != INT_MAX? min_len: 0;
    }
};