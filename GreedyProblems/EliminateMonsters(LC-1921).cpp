class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time;
        for(int i=0; i<n; i++)
            time.push_back(1.0*dist[i]/speed[i]);
        
        sort(time.begin(), time.end());

        int monsters = 1;
        for(int i=1; i<n; i++){
            if(time[i]<=i)
                break;
            monsters++;
        }
        
        return monsters;
    }
};