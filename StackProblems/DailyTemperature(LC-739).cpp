class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        stack<int> s;
        
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[i]>=arr[s.top()])
                s.pop();
            if(s.empty()){
                result.push_back(0);
            }else{
                result.push_back(s.top()-i);
            }
            s.push(i);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};