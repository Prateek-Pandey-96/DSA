class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> range_map(26, {-1, -1});
        int n = s.length();

        /*Save the ranges*/
        for(int i=0; i<n; i++){
            int idx = s[i]-'a';
            if(range_map[idx].first == -1)
                range_map[idx] = {i, i};
            else
                range_map[idx].second = i;
        }

        int idx = 0;
        vector<int> result;

        /*Climb the ladder*/
        while(idx < n){
            int start = range_map[s[idx]-'a'].first, end = range_map[s[idx]-'a'].second;
            for(int i = start; i<=end; i++){
                end = max(end, range_map[s[i]-'a'].second);
            }
            result.push_back(end-start+1);
            idx = end+1;
        }
        
        return result;
    }
};