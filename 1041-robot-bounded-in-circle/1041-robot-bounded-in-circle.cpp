class Solution {
public:
    bool isRobotBounded(string dir) {
        int x = 0, y = 0, dx = 0, dy = 1,tmp;
        for(auto c:dir)
            if( c=='L')tmp=dx,dx=-dy,dy=tmp;
            else if( c=='R')tmp=dy,dy=-dx,dx=tmp;
            else x+=dx,y+=dy;
        
        return (x==0&&y==0)||dx!=0||dy!=1;
    }
};