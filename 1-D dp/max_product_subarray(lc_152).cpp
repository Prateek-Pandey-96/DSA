class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int max_so_far = INT_MIN;
        for(auto ele: arr)
            max_so_far = max(ele, max_so_far);
        
        int local_max = 1;
        int local_min = 1;

        for(int i=0; i<n; i++){
            int mx = max({arr[i], local_min*arr[i], local_max*arr[i]});
            int mn = min({arr[i], local_min*arr[i], local_max*arr[i]});
            max_so_far = max({max_so_far, mx});
            local_max = mx;
            local_min = mn;
        }
        return max_so_far;
    }
};