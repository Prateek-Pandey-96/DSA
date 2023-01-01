class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int len = A.size();
        vector<int> lv, rv;
        stack<int> ls, rs;

        for(int i=0; i<len; i++){

            while(!ls.empty() && A[i] <= A[ls.top()]) 
                ls.pop();
            if(ls.empty()) 
                lv.push_back(-1);
            else 
                lv.push_back(ls.top());
            ls.push(i);

            while(!rs.empty() && A[len-1-i] <= A[rs.top()]) 
                rs.pop();
            if(rs.empty()) 
                rv.push_back(len);
            else 
                rv.push_back(rs.top());
            rs.push(len-1-i);
        } 
        reverse(rv.begin(), rv.end());
        int max_area = 0;
        for(int i=0; i<len; i++){
            max_area = max(max_area, (rv[i]-lv[i]-1) * A[i]);
        }
        return max_area;
    }
};