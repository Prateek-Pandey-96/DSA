/*Dp solution O(n*n) memoize decision tree*/
class Solution {
public:
    int dp[101][101];
    int DFS(vector<vector<int>>& costs, int idx, int a_count, int b_count){
        if(idx == costs.size()-1){
            if(a_count == b_count-1 and b_count == costs.size()/2)
                return costs[idx][0];
            if(b_count == a_count-1 and a_count == costs.size()/2)
                return costs[idx][1];
            return 10001;
        }
        
        if(dp[a_count][b_count]!=-1)
            return dp[a_count][b_count];
        
        int option1 = costs[idx][0] + DFS(costs, idx+1, a_count+1, b_count);
        int option2 = costs[idx][1] + DFS(costs, idx+1, a_count, b_count+1);
        
        return dp[a_count][b_count] = min(option1, option2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp, -1, sizeof dp);
        int ans = DFS(costs,0, 0, 0);
        return ans;
    }
};

/*Greedy solution O(nlogn) sorting*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<pair<int, int>> diff(n);
        for(int i=0;i<n;i++){
            diff[i] = {costs[i][0] - costs[i][1], i};
            
        }
        sort(diff.begin(), diff.end());
        int total_cost = 0;
        
        int i=0;
        for(;i<n/2;i++)total_cost+=costs[diff[i].second][0];
        for(;i<n;i++)total_cost+=costs[diff[i].second][1];
        
        return total_cost;
    }
};