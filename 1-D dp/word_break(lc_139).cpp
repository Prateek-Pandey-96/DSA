class Solution {
public:
    // unordered_map<int, bool> cache;
    // bool DFS(string s, int idx, unordered_set<string>& words){
    //     if(idx == s.length() || words.count(s.substr(idx))) 
    //         return cache[idx] = true;
    //     if(cache.count(idx))
    //         return cache[idx];
    //     string first = "";
    //     for(int i=idx; i<s.length(); i++){
    //         first.push_back(s[i]);
    //         if(words.count(first))
    //         {
    //             if(DFS(s, i+1, words))
    //                 return cache[idx]=true;
    //         }
    //     }
    //     return cache[idx]=false;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set<string> words(wordDict.begin(), wordDict.end());
        // return DFS(s, 0, words);
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;

        for(int i=1; i<=s.length(); i++){
            for(auto word: wordDict){
                if(word.length() <= i and s.substr(i-word.length(), word.length()) == word){
                    dp[i] = dp[i-word.length()];
                    if(dp[i])
                        break;
                } 
            }
        }

        return dp[s.length()];
    }
};