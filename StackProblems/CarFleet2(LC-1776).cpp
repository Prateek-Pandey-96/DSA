class Solution {
public:
    double calculate_time(vector<int>& a, vector<int>& b){
        int distance = b[0]-a[0];
        int relative_speed = -1*(b[1] - a[1]);
        return (double)distance/(double)relative_speed;
    }
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> time(n, -1.0);
        stack<int> s;
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() and cars[s.top()][1] >= cars[i][1])
                s.pop();
            while(!s.empty() and time[s.top()] > 0.0 and calculate_time(cars[i], cars[s.top()]) > time[s.top()])
                s.pop();
            if(s.empty())
                time[i] = -1.0;
            else
                time[i] = calculate_time(cars[i], cars[s.top()]);
            s.push(i);
        }
        
        return time;
    }
};