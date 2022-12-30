class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> pos_speed;
        for(int i=0; i<n; i++)
            pos_speed.push_back({position[i], speed[i]});
        sort(pos_speed.begin(), pos_speed.end());
        
        vector<double> time;
        for(int i=0; i<n; i++)
            time.push_back(1.0*(target - pos_speed[i].first)/pos_speed[i].second);
        
        stack<double> s;
        for(int i=0; i<n; i++){
            while(!s.empty() and time[i] >= s.top()) s.pop();
            s.push(time[i]);
        }
        
        return s.size();
    }
};