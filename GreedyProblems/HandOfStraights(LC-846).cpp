class Solution {
public:
    bool isNStraightHand(vector<int>& hands, int groupSize) {
        unordered_map<int, int> hashmap;
        for(int hand: hands) hashmap[hand]++;
        
        int n = hands.size();
        if(n%groupSize != 0) return false;

        sort(hands.begin(), hands.end());
        
        for(int i=0; i<n; i++){
            if(hashmap[hands[i]]!=0){
                int start = hands[i], k=0;
                while(hashmap[start]!=0 and k!=groupSize){
                    hashmap[start]--;
                    start++;
                    k++;
                }
                if(k!=groupSize)
                    return false;
            }
        }
        return true;
    }
};