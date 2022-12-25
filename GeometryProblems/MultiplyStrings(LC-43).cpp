class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        int n = num1.length(), m = num2.length();
        if(n < m) return multiply(num2, num1);
        
        string ans(n+m, '0');
        int start = 0;
        
        for(int i=m-1; i>=0; i--){
            int carry = 0, ans_idx=start++;
            for(int j=n-1; j>=0; j--){
                int sum = (num2[i]-'0')*(num1[j]-'0')+carry;
                sum += (ans[ans_idx] - '0');
                ans[ans_idx] = sum%10 + '0';
                carry = sum/10;
                ans_idx++;
            }
            if(carry)
            {
                int sum = carry;
                sum += (ans[ans_idx] - '0');
                ans[ans_idx] = sum%10 + '0';
                carry = sum/10;
                ans_idx++;
            }
        }
        
        reverse(ans.begin(), ans.end());
        int idx = 0;
        while(ans[idx]=='0')idx++;
        return ans.substr(idx);
    }
};