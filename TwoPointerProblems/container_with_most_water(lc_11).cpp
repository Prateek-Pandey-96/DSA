class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=n-1;
        int max_water = (j-i) * min(arr[i], arr[j]);
        
        while( i < j ){
            if(arr[i] < arr[j])i++;
            else j--;
            max_water = max(max_water, (j-i) * min(arr[i], arr[j]));
        }
        
        return max_water;
    }
};