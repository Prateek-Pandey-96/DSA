class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int t=0, l=0;
        int b=m-1, r=n-1;
        int k;
        
        while(l<=r and t<=b){
            k=l;
            while(k<=r){
                result.push_back(matrix[t][k]);
                
                k++;
            }
            t++;
            if(t>b)break;
            k=t;
            while(k<=b){
                result.push_back(matrix[k][r]);
                
                k++;
            }
            r--;
            if(r<l)break;
            k=r;
            while(k>=l){
                result.push_back(matrix[b][k]);
                
                k--;
            }
            b--;
            if(t>b)break;
            k=b;
            while(k>=t){
                result.push_back(matrix[k][l]);
                
                k--;
            }
            
            l++;
            if(r<l)break;
        }
        return result;
    }
};