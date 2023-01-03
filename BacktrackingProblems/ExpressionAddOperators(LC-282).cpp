class Solution {
public:
    vector<string> ans;
    long dest;
    
    void DFS(string num, long idx, long curr, long prev_num, string path){
        if(idx == num.length()){
            if(curr == dest)
                ans.push_back(path);
            return;
        }
        
        
        long temp_num = 0;
        string temp_string = "";
        for(int i=idx; i<num.length(); i++)
        {
            if(num[idx]=='0' and i!=idx) continue;
            temp_num = temp_num * 10 + (num[i]-'0');
            temp_string = temp_string + num[i];
            if(idx == 0)
            {
                DFS(num, i+1, curr+temp_num, temp_num, path + temp_string);
            }else{
                DFS(num, i+1, curr+temp_num, temp_num, path + "+" + temp_string);
                DFS(num, i+1, curr-temp_num, -temp_num, path + "-" +  temp_string);
                DFS(num, i+1, (curr-prev_num)+prev_num*temp_num, prev_num*temp_num, path + "*" + temp_string);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        ans.clear();
        dest = target;
        DFS(num, 0, 0, 0, "");
        return ans;
    }
};