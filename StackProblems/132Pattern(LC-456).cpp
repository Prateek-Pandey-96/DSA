class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        int min_element = nums[0];
        stack<pair<int, int>> s;
        s.push({nums[0], min_element});
        
        for(int i=1; i<n; i++){
            min_element = min(nums[i], min_element);
            while(!s.empty() and nums[i] >= s.top().first)
                s.pop();
            if(!s.empty() and nums[i] > s.top().second and s.top().first > s.top().second)
                return true;

            s.push({nums[i], min_element});
        }
        
        return false;
    }
};