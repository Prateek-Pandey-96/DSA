class Solution {
public:
    string minWindow(string s, string t) {
        /*Base Case*/
        if(t.length() > s.length())
            return "";
        
        unordered_map<char, int> ques, ans;
        int n = t.length();

        for(int i=0; i<n; i++)
            ques[t[i]]++;


        int rmc = n;  // required match count
        int mc = 0;   // match count

        int min_len = INT_MAX;
        int j = 0, i = 0;
        int sp = -1;
        while(j < s.length()){
            ans[s[j]]++;
            if(ques.count(s[j]) and ans[s[j]]<=ques[s[j]]){
                mc++;
            }

            if(mc==rmc){

                while(!ques.count(s[i]) || ans[s[i]]>ques[s[i]])
                {
                    ans[s[i++]]--;
                }

                if(j-i+1 < min_len){
                    min_len = j-i+1;
                    sp = i;
                }
                ans[s[i++]]--;
                mc--;
            }

            j++;
        }
       
        if(sp==-1)
            return "";
        
        return s.substr(sp, min_len);
    }
};