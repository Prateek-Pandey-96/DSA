class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int len = -1;
        string ans = "";
        for(int i=0; i<n; i++){
            /*Checking for odd lengths*/
            int l = i, r = i;
            while(l >= 0 and r < n and s[l]==s[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--, r++;
            }
            /*Checking for even lengths*/
            l=i, r=i+1;
            while(l >= 0 and r < n and s[l]==s[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--, r++;
            }
        }
        return ans;
    }
};