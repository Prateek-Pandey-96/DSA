class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open_min = 0, open_max = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '(') open_min++, open_max++;
            else if(s[i] == ')') open_min--, open_max--;
            else open_min--, open_max++;
            
            if(open_min < 0) open_min = 0;
            if(open_max < 0) return false;
        }
        return open_min == 0;
    }
};