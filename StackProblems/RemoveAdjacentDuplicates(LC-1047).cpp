class Solution {
public:
    string removeDuplicates(string str) {
        /*Use string as a stack to save space*/
        string s;
        for(char c: str){
            if(s.empty() || s.back()!=c) 
            {
                s.push_back(c);
            }
            else if(s.back()==c)
            {
                s.pop_back();
            }
        }
        return s;
    }
};