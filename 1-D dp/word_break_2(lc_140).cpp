class Solution {
public:
    unordered_set<string> words;
    unordered_map<int, vector<string>> cache;
    vector<string> DFS(string s, int idx){
        if(idx==s.length())
            return {""};
        
        if(cache.count(idx))
            return cache[idx];
        
        string first;
        vector<string> ans;

        for(int i=idx; i<s.length(); i++){
            first.push_back(s[i]);
            if(words.count(first)){
                vector<string> recursive_results = DFS(s, i+1);
                for(auto res: recursive_results){
                    string temp = first + " " + res;
                    ans.push_back(temp); 
                }
            }
        }
        return cache[idx] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict)
            words.insert(word);
        
        vector<string> combinations = DFS(s, 0);
        for(auto& combination: combinations)
            combination.pop_back();
        return combinations;
    }
};