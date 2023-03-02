class Solution {
public:
    int minFlips(string str) {
        string newstr = str + str;
        int n = str.length();

        string x(2*n, '0'), y(2*n, '0');
        for(int i=0; i<2*n; i++){
            if(i % 2 == 0)
                x[i]='1';
            else
                y[i]='1';
        }
        
        int diff1=0, diff2=0, res = n;
        for(int i=0; i<n; i++){
            if(newstr[i]!=x[i]) diff1++;
            if(newstr[i]!=y[i]) diff2++;
        }
        res = min(diff1, diff2);

        for(int i=n; i<2*n; i++){
            if(newstr[i]!=x[i]) diff1++;
            if(newstr[i-n]!=x[i-n]) diff1--;

            if(newstr[i]!=y[i]) diff2++;
            if(newstr[i-n]!=y[i-n]) diff2--;

            res = min({res, diff1, diff2});
        }
        return res;
    }
};