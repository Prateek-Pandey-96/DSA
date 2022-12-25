class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long size = rolls.size(), sum = 0;
        for(long roll: rolls)
            sum += roll;

        long rem_sum = (size+n) * mean - sum;
        if(rem_sum < n || rem_sum > n*6)
            return {};
        
        vector<int> result(n, rem_sum/n);
        int manual_distribution = rem_sum%n;
        for(int i=0; i<manual_distribution; i++)
            result[i]++;
        
        return result;
    }
};