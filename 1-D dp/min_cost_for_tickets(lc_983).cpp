class Solution {
public:
    int minCost(vector<int>& days, int idx, vector<int>& costs, vector<int>& dp){
        if(idx == days.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int c1 = costs[0], c7 = costs[1], c30 = costs[2];
        
        /*Bought 1 day pass*/
        int p1 = c1 + minCost(days, idx+1, costs, dp);
        
        /*Bought 7 day pass*/
        int i = idx;
        while(i<days.size() and days[i] < days[idx]+7){
            i++;
        }
        int p2 = c7 + minCost(days, i, costs, dp);

        /*Bought 30 day pass*/
        i=idx;
        while(i<days.size() and days[i] < days[idx]+30){
            i++;
        }
        int p3 = c30 + minCost(days, i, costs, dp);

        return dp[idx]=min({p1, p2, p3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*Each day we have a choice for 3 passes*/
        vector<int> dp(days.size(), -1);
        return minCost(days, 0, costs, dp);
    }
};