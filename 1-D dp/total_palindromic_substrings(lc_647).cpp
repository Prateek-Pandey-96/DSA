class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++){
            /*Checking for odd lengths*/
            int l = i, r = i;
            while(l >= 0 and r < n and s[l]==s[r]){
                count++;
                l--, r++;
            }
            /*Checking for even lengths*/
            l=i, r=i+1;
            while(l >= 0 and r < n and s[l]==s[r]){
                count++;
                l--, r++;
            }
        }
        return count;
    }
};