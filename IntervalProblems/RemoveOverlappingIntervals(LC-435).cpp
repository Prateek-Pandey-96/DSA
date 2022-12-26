class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return 0;
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1];
        int count = 0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] < end)
                count++, end = min(end, intervals[i][1]);
            else
                end = intervals[i][1];
        }
        
        return count;
    }
};