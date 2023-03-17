class Solution {
public:
    bool DFS(vector<int>& nums, int idx, int target, vector<vector<int>>& cache){
        if(target==0)
            return true;
        if(idx == nums.size())
            return false;
        
        if(cache[idx][target]!=-1)
            return cache[idx][target];
        
        if(target >= nums[idx])
        {
            bool include = DFS(nums, idx+1, target-nums[idx], cache);
            bool exclude = DFS(nums, idx+1, target, cache);
            return cache[idx][target] = (include || exclude)? 1: 0;
        }
        return cache[idx][target] = DFS(nums, idx+1, target, cache);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums)
            sum += num;
        if(sum%2)
            return false;
        int required_sum = sum/2;

        /* Wrong answer for [1, 1, 2, 2] */
        // sort(nums.begin(), nums.end());
        // int temp_sum = 0;
        // for(auto num: nums){
        //     temp_sum += num;
        //     if(temp_sum == required_sum)
        //         return true;
        // }
        // return false;
        vector<vector<int>> cache(nums.size()+1, vector<int>(required_sum+1, -1));
        return DFS(nums, 0, required_sum, cache);
    }
};