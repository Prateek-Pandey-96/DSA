class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap;
        hashmap['I'] = 1;
        hashmap['V'] = 5;
        hashmap['X'] = 10;
        hashmap['L'] = 50;
        hashmap['C'] = 100;
        hashmap['D'] = 500;
        hashmap['M'] = 1000;
        int ans = 0, n = s.length();
        int i;
        for(i=0; i<n-1; i++){
            if(hashmap[s[i]]>=hashmap[s[i+1]])
                ans += hashmap[s[i]];
            else{
                ans += hashmap[s[i+1]]-hashmap[s[i]];
                i++;
            }
        }
        
        if(i!=n)
            ans += hashmap[s[i]];
        
        return ans;
    }
};