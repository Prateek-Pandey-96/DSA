class Solution {
public:
    vector<string> result;
    void DFS(int n, int open, int close, string path){
        if(path.length() == 2*n){
            result.push_back(path);
        }
        
        if(open < n) DFS(n, open+1, close, path + "(");
        if(close < open) DFS(n, open, close+1, path + ")");
    }
    vector<string> generateParenthesis(int n) {
        result.clear();
        DFS(n, 0, 0, "");
        return result;
    }
};