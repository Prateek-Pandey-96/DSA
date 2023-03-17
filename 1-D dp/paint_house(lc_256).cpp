#include <bits/stdc++.h>
using namespace std;
 

int minCost(vector<vector<int>>& costs, int N)
{
    // Corner Case
    if (N == 0)
        return 0;
 
    // Auxiliary 2D dp array
    vector<vector<int> > dp(
        N, vector<int>(3, 0));
 
    // Base Case
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
 
    for (int i = 1; i < N; i++) {
 
        // If current house is colored
        // with red the take min cost of
        // previous houses colored with
        // (blue and green)
        dp[i][0] = min(dp[i - 1][1],
                       dp[i - 1][2])
                   + costs[i][0];
 
        // If current house is colored
        // with blue the take min cost of
        // previous houses colored with
        // (red and green)
        dp[i][1] = min(dp[i - 1][0],
                       dp[i - 1][2])
                   + costs[i][1];
 
        // If current house is colored
        // with green the take min cost of
        // previous houses colored with
        // (red and blue)
        dp[i][2] = min(dp[i - 1][0],
                       dp[i - 1][1])
                   + costs[i][2];
    }
 
    // Print the min cost of the
    // last painted house
    return min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
}


* do paint house 3 also