class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        
        for(auto ch: str){
            if(ch == '(')
                s.push(-1);
            else{
                int sum = 0;
                while(!s.empty() and s.top()!=-1){
                    sum += s.top();
                    s.pop();
                }
                s.pop();
                if(sum == 0)
                    s.push(1);
                else
                    s.push(2*sum);
            }
        }
        
        int ans = 0;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        return ans;
    }
};