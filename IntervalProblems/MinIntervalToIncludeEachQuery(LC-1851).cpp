class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int q = queries.size();
        
        vector<pair<int, int>> queries_with_idx;
        for(int i=0; i<q; i++) 
            queries_with_idx.push_back({queries[i], i});
        sort(queries_with_idx.begin(), queries_with_idx.end());
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> result(q, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int intervals_it = 0;
        
        for(int i=0; i<q; i++){
            /*Include intervals that can contain the query*/
            while(intervals_it < intervals.size() and intervals[intervals_it][0] <= queries_with_idx[i].first){
                minHeap.push({intervals[intervals_it][1]-intervals[intervals_it][0]+1, intervals[intervals_it][1]});
                intervals_it++;
            }

            /*Pop intervals that end earlier than query*/
            while(!minHeap.empty() and minHeap.top().second < queries_with_idx[i].first)
                minHeap.pop();
            
            /*Generate result*/
            if(minHeap.empty())
                 result[queries_with_idx[i].second] = -1;
            else
                result[queries_with_idx[i].second] = minHeap.top().first;
        }
        
        return result;
    }
};