class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        /*Basic initial constants*/
        int sum = 0, count = 0, n = arr.size();
        
        /*Make first window*/
        for(int i=0; i<k; i++)
            sum += arr[i];
        
        if(sum/k >= threshold)
            count++;

        /*Slide the window*/
        for(int i=k; i<n; i++){
            sum = sum + arr[i] - arr[i-k];
            if(sum/k >= threshold)
                count++;
        }

        return count;
    }
};