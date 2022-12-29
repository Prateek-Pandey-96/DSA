class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char, int>> s;
        
        for(int i=str.length()-1; i>=0; i--){
            char ch = str[i];
            if(s.empty() || ch!=s.top().first){
                s.push({ch, 1});
            }else if(ch == s.top().first){
                auto [prev_ch, freq] = s.top();
                s.pop();
                if(freq < k-1)
                    s.push({ch, freq+1});
            }
        }
        
        string result;
        while(!s.empty()){
            auto [ch, freq] = s.top();
            s.pop();
            while(freq--)
                result.push_back(ch);
        }
        return result;
    }
};