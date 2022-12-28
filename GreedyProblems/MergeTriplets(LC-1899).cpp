class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      unordered_set<int> bad_pos;
      for(int i=0; i<triplets.size(); i++){
        if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
          bad_pos.insert(i);
        }
      }
      
      bool a=false, b=false, c=false;
      for(int i=0; i<triplets.size(); i++){
        if(bad_pos.count(i)) continue;
        if(triplets[i][0] == target[0]) a = true;
        if(triplets[i][1] == target[1]) b = true;
        if(triplets[i][2] == target[2]) c = true;
      }
      return a and b and c;
    }
};