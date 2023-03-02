/*This is the actual O(n) solution*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) return false;
        
        vector<int> ques(26, 0), ans(26, 0);
        for(auto ch: s1) 
            ques[ch-'a']++;
        for(int i=0; i<n1; i++) 
            ans[s2[i]-'a']++;
        
        int matches = 0;
        for(int i=0; i<26; i++)
            if(ques[i]==ans[i])
                matches++;
        if(matches==26) 
            return true;
            
        for(int i=n1; i<n2; i++){
            int j = i-n1;
            ans[s2[i]-'a']++;
            ans[s2[j]-'a']--;

            if(ans[s2[i]-'a']==ques[s2[i]-'a'])
                matches++;
            else if(ans[s2[i]-'a']==ques[s2[i]-'a']+1)
                matches--;

            if(ans[s2[j]-'a']==ques[s2[j]-'a'])
                matches++;
            else if(ans[s2[i]-'a']==ques[s2[i]-'a']-1)
                matches--;

            if(matches == 26)
                return true;
        }
        
        return false;
    }
};