class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int n = asteroids.size();
  
        for(int i=0; i<n; i++){
            int asteroid = asteroids[i];
            if(asteroid > 0)
                result.push_back(asteroid);
            else{
                while(result.size() and result.back() > 0 and result.back() < -1*asteroid) 
                    result.pop_back();
                if(result.size()==0 || result.back()<0)
                    result.push_back(asteroid);
                else if(result.back() == -1*asteroid)
                    result.pop_back();
            }
        }
        
        return result;
    }
};