class Solution {
public:
    string decodeString(string s) {
        string temp, helper, num;

        
        for(auto ch: s){
            if(ch != ']')
                temp.push_back(ch);
            else{
                helper = "", num = "";
                
                /*Get the nested substring*/
                while(temp.size() and temp.back()!='['){
                    helper.push_back(temp.back());
                    temp.pop_back();
                }
                temp.pop_back();
                reverse(helper.begin(), helper.end());
                
                /*Get the multiplication factor*/
                while(temp.size() and temp.back() >= '0' and temp.back() <= '9'){
                    num.push_back(temp.back());
                    temp.pop_back();
                }
                reverse(num.begin(), num.end());
                
                int int_num = stoi(num);
                while(int_num--)
                    temp = temp + helper;
            }
        }
        
        return temp;
    }
};