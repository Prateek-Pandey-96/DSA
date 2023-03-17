class Solution {
public:
    int getIndex(vector<int>& seq, int element){
        int low = 0;
        int high = seq.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(seq[mid] > element){
                ans = mid;
                high = mid-1;
            }else if(seq[mid] < element){
                low = mid+1;
            }else{
                ans = mid;
                break;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& a) {
        vector<int> seq;
   
           for(int i=0;i<a.size();i++){
                if(seq.empty() or a[i]>seq.back())
                    seq.push_back(a[i]);
                else{
                    int index = getIndex(seq, a[i]);
                    seq[index] = a[i];
                }
           }
        //    for(auto el: seq) cout<<el<<" ";
           return seq.size();
    }
};