class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size();

        for(int i=1; i<depth; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j==triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<depth; j++){
            ans = min(ans, triangle[depth-1][j]);
        }

        return ans;
    }
};