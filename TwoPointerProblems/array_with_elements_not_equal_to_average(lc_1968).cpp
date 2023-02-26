class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*Wiggle sort*/
        
        /*Assuming first decreasing*/
        bool dir = false;
        /*Flip if increasing*/
        if(nums[1] > nums[0])
            dir = true;
        
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(nums[i] > nums[i-1]){
                if(dir == true)
                    swap(nums[i], nums[i-1]);
            }else{
                if(dir == false)
                    swap(nums[i], nums[i-1]);
            }
            dir = !dir;
        }
        
        return nums;
    }
};

