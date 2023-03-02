class MySolution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        vector<pair<int, int>> temp(n, {0, 0});
        for(int i=0; i<n; i++)
            temp[i] = {abs(arr[i]-x), i};
        
        sort(temp.begin(), temp.end(), compare);
        for(int i=0; i<k; i++)
            res.push_back(arr[temp[i].second]);
        
        sort(res.begin(), res.end());
        return res;
    }
};
