class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        if(n==1 || n==2)
            return 0;
        
        int low = 1, high = n-2;
        int lmax = height[0], rmax = height[n-1];
        
        while(low <= high){
            if(lmax < rmax){
                lmax = max(lmax, height[low]);
                water += lmax - height[low];
                low++;
            }else{
                rmax = max(rmax, height[high]);
                water += rmax - height[high];
                high--;
            }
        }

        return water;
    }
};