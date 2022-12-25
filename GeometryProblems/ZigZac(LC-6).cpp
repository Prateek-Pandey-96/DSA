class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        bool dir = true; //true for down false for up
        string temp[numRows];
        string result;
        int row = 0;
        for(int i=0;i<s.length();i++)
        {        
            temp[row].push_back(s[i]);
            if(row == numRows-1)
                dir=false;   
            if(row == 0)
                dir = true;    
            dir?row++:row--;
        }

        for(int i=0;i<numRows;i++)
            result+=temp[i];
        return result;
    }
};