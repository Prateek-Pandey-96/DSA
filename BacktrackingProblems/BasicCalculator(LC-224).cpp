class Solution {
public:
    int ans;
    
    /*Returns next index to, index till which scanning is done*/
    int recursive_helper(string s, int idx, int entry_sign){
        int i = idx;
        int local_value = 0, sign = 1;
        while(i < s.length() and s[i]!=')'){
            if(s[i]=='-')
            {
                sign = -1;
                i++;
            }
            if(s[i]=='+')
            {
                sign = 1;
                i++;
            }
            if(s[i]=='(')
            {
                int next_idx = recursive_helper(s, i+1, entry_sign*sign);
                i = next_idx;
                continue;
            }
            int temp_value = 0;
            while(i < s.length() and s[i] >= '0' and s[i] <= '9'){
                temp_value = 10 * temp_value + (s[i]-'0');
                i++;
            }
            local_value = local_value + sign*temp_value;
        }
        
        ans = ans + entry_sign*local_value;
        return i+1;
    }
    
    int calculate(string s) {
        ans = 0;
        string ref_str;
        for(auto ch: s)
            if(ch != ' ')
                ref_str.push_back(ch);
        s = "(" + ref_str + ")";
        int garbage_value = recursive_helper(s, 1, 1);
        return ans;
    }
};