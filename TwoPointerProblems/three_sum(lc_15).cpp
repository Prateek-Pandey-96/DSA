class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> result;
        if(n<3) return result;
        
        for(int i=0; i<n;){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum==0) 
                {
                    result.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                    while(j<k and arr[j]==arr[j-1]) j++;
                    while(j<k and arr[k]==arr[k+1]) k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
            i++;
            while(i<n and arr[i]==arr[i-1])i++;
        }
        
        return result;
    }
};