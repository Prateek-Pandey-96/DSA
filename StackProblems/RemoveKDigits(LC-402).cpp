class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(num[0]=='0' || k == n)
            return "0";
        
        string result;
        for(int i=0; i<n; i++){
            while(result.size() and num[i] < result.back() and k){
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }
        
        while(k--)
            result.pop_back();
        
        int start_idx = 0;
        while(result[start_idx]=='0')
            start_idx++;
        
        if(start_idx == result.size())
            return "0";
        return result.substr(start_idx);
    }
};