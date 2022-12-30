class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> canonical;
        string temp;
        
        /*Step-1 Seperation based on slashes*/
        for(int i=0; i<n; i++){
            if(path[i]=='/'){
                if(temp.size())
                    canonical.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(path[i]);
        }
        if(temp.size())
            canonical.push_back(temp);
        
        /*Step-2 Applying the algorithm*/
        vector<string> ans;
        for(int i=0; i<canonical.size(); i++){
            if(canonical[i]==".") continue;
            else if(canonical[i]==".." and ans.size()!=0) ans.pop_back();
            else if(canonical[i]=="..") continue;
            else ans.push_back(canonical[i]);
        }
        
        /*Step-3 Form the result*/
        string result;
        for(int i=0; i<ans.size(); i++){
            result += "/";
            result += ans[i];
        }
        if(result.size()==0)
            return "/";
        return result;
    }
};