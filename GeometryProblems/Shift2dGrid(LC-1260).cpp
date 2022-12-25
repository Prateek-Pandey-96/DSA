class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        /*
        (i, j) to 1-d idx -> idx = i*n+j
        1-d idx to (i, j) -> row = idx/n, col = idx%n
        */
        k = k%(m*n);
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int temp_idx = (i*n+j+k)%(m*n);
                res[temp_idx/n][temp_idx%n] = grid[i][j];
            }
        }
        
        return res;
    }
};