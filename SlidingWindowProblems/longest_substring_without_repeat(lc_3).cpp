class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        if(n==0 || n==1) return n;
        
        unordered_map<char, int> hashMap;
        int i=0, j=0;
        int mxLen = 0;
        while(j<n)
        {
            hashMap[s[j]]++;
            
            while(hashMap[s[j]] > 1){
                hashMap[s[i]]--;
                i++;
            }
         
            mxLen = max(mxLen, j-i+1);
            j++;
        }
        return mxLen;
    }
};