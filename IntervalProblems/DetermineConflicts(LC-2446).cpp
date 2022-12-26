class Solution {
public:
    int integer_time(string t){
        return 100 * stoi(t.substr(0, 2)) + stoi(t.substr(3));
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string e1_start = event1[0], e1_end = event1[1];
        string e2_start = event2[0], e2_end = event2[1];
        
        int x1 = integer_time(e1_start), x2 = integer_time(e2_start);
        int y1 = integer_time(e1_end), y2 = integer_time(e2_end);
        
        if(x1 <= x2 and y1 >= x2) return true;
        if(x2 <= x1 and y2 >= x1) return true;
        
        return false;
    }
};