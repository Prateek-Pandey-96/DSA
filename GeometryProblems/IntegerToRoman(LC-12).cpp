class Solution {
public:
    string intToRoman(int sum) {
        vector<string> rep = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> val = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int idx = 12;
        string ans;
        while(sum){
            while(sum >= val[idx]){
                ans += rep[idx];
                sum -= val[idx];
            }
            idx -= 1;
        }
        return ans;
    }
};