class Solution {
public:
//     int ans;
//     Memory limit exceeded for recursive solution
//     void recursive_helper(string s, int idx, int ans_till_now, int prev_num){
//         if(idx > s.length())
//             return;
//         if(idx == s.length())
//         {       
//             ans = ans_till_now;
//             return;
//         }
        
//         int curr_num = 0;
//         char symbol = s[idx++];
//         while(idx < s.length() and s[idx]>='0' and s[idx]<='9'){
//             curr_num = curr_num*10 + (s[idx]-'0');
//             idx++;
//         }

//         if(symbol == '+')
//             recursive_helper(s, idx, ans_till_now + curr_num, curr_num);
//         else if(symbol == '-')
//             recursive_helper(s, idx, ans_till_now - curr_num, -curr_num);
//         else if(symbol == '*')
//             recursive_helper(s, idx, (ans_till_now-prev_num) + prev_num * curr_num, prev_num * curr_num);
//         else if(symbol == '/')
//             recursive_helper(s, idx, (ans_till_now - prev_num) + prev_num/curr_num, prev_num/curr_num);
//     }
    
    int calculate(string s) {
        string ref_str;
        for(auto ch: s)
            if(ch != ' ')
                ref_str.push_back(ch);
        s = ref_str;
        long ans = 0;
        long curr_num = 0, idx = 0;
        while(s[idx]>='0' and s[idx]<='9'){
            curr_num = curr_num*10 + (s[idx]-'0');
            idx++;
        }
        // recursive_helper(s, idx, curr_num, curr_num);
        stack<int> st;
        st.push(curr_num);
        long prev_num = curr_num;
        
        while(idx<s.length()){
            long temp = 0;
            char symbol = s[idx++];
            while(idx < s.length() and s[idx]>='0' and s[idx]<='9'){
                temp = temp*10 + (s[idx]-'0');
                idx++;
            }
            
            if(symbol == '+'){
                st.push(st.top()+temp);
                prev_num = temp;
            }
            else if(symbol == '-'){
                st.push(st.top()-temp);
                prev_num = -temp;
            }
            else if(symbol == '*'){
                st.push((st.top()-prev_num) + prev_num*temp);
                prev_num = prev_num*temp;
            }
            else if(symbol == '/'){
                st.push((st.top()-prev_num) + prev_num/temp);
                prev_num = prev_num/temp;
            }
        }
        
        return (int)st.top();
    }
};

/*Can be done without stack too in O(1)*/