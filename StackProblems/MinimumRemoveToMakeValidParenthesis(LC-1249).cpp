class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(')open++;
            else if(s[i]==')'){
                open--;
                if(open<0){
                    open = 0;
                    s[i] = '#';
                }
            }
        }
        int close = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')')close++;
            else if(s[i]=='('){
                close--;
                if(close < 0){
                    close = 0;
                    s[i]='#';
                }
            }
        }
        string ans;
        for(auto ch:s)
            if(ch!='#')
                ans.push_back(ch);
        
        return ans;
    }
};