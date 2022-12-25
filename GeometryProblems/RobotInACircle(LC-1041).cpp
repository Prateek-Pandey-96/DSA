class Solution {
public:
    bool isRobotBounded(string instructions) {
        int sx = 0, sy = 0, ex = 0, ey = 0;
        int direction = 0; //north

        for(char ch: instructions){
            if(ch == 'L') {
                direction = (direction-1)%4;
                if(direction < 0)
                    direction += 4;
            }
            else if(ch == 'R') {
                direction = (direction+1)%4;
                if(direction < 0)
                    direction += 4;
            }
            else{
                if(direction == 0){
                    ey++;
                }else if(direction == 1){
                    ex++;
                }else if(direction == 2){
                    ey--;
                }else{
                    ex--;
                }
            }
        }
        
        if((ex == sx and ey == sy) || direction != 0) 
            return true;

        return false;
    }
};