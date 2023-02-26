class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;){
            for(int j=i+1; j<n;){
                int low = j+1, high = n-1;
                while(low < high ){
                    long sum = (long)nums[low] + (long)nums[high] + (long)nums[i] + (long)nums[j];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                        while(low<high and nums[low]==nums[low-1])low++;
                        while(low<high and nums[high]==nums[high+1])high--;
                    }else if(sum > target)
                        high--;
                    else 
                        low++;
                    
                }
                j++;
                while(j<n and nums[j]==nums[j-1])j++;
            }
            i++;
            while(i<n and nums[i]==nums[i-1])i++;
        }
        return result;
    }
};