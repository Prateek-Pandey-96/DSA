class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return 1;
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1], count = 0;
        
        for(int i=1; i<n; i++){
            if(intervals[i][0] > end){
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                if(intervals[i][1] <= end)
                    count++;
                else if(start == intervals[i][0] and end <= intervals[i][1]){
                    count++;
                    start = intervals[i][0];
                    end = intervals[i][1];
                }else{
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
        }
        
        return n-count;
    }
};