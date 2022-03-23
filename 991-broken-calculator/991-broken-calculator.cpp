class Solution {
public:
    int brokenCalc(int X, int Y) {
        // 11 10
        int cnt=0;
        while(Y>X){
            if(Y%2==0)Y/=2;
            else Y++;
            cnt++;
        }
        while(X>Y){
            return cnt+X-Y; 
        }
        return cnt;
    }
};


        
  
