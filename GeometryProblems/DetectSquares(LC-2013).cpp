/*Time -> O(n), Space -> O(n) n = number of points*/
class DetectSquares {
public:
    int grid[1001][1001];
    vector<pair<int, int>> points;
    
    DetectSquares() {
        memset(grid, 0, sizeof grid);
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points.push_back({x, y});
        grid[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], cnt = 0;
        for(auto curr_point: points){
            /*Overlapping point -> ignore*/
            if(x == curr_point.first and y == curr_point.second) continue;
            if(abs(x - curr_point.first) == abs(y - curr_point.second))
                cnt += grid[x][curr_point.second] * grid[curr_point.first][y];
        }
        return cnt;
    }
};