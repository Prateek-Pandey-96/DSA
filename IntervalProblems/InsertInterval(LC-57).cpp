class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), idx=0;
        int start = newInterval[0], end = newInterval[1];
        
        vector<vector<int>> result;
        /*Include all which end before new interval starts*/
        while(idx < n and intervals[idx][1] < start)
        {
            result.push_back(intervals[idx]);
            idx++;
        }        
        
        /*Take intersection*/
        while(idx < n and intervals[idx][0] <= end){
            start = min(start, intervals[idx][0]);
            end = max(end, intervals[idx][1]);
            idx++;
        }
        result.push_back({start, end});
        
        /*Add remaining intervals*/
        while(idx != n){
            result.push_back(intervals[idx]);
            idx++;
        }
        
        return result;
    }
};