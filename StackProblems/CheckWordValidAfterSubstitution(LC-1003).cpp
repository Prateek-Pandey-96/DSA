class Solution {
public:
    bool isValid(string s) {
        string st;
        
        for(auto ch: s){
            st.push_back(ch);

            while(st.size() >= 3 and st.back() == 'c'){
                st.pop_back();
                
                if(st.back()=='b') 
                    st.pop_back();
                else 
                    return false;
                
                if(st.back()=='a') 
                    st.pop_back();
                else 
                    return false;
            }
        }
        
        return st.size() == 0;
    }
};