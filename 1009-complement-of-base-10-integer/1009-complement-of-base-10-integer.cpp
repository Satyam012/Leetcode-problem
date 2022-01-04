class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        int i=31,m=0;
        for(;i>=0;i--){
            int x=1<<i;
            if(x&N)break;
        }
        
        for(;i>=0;i--){
            int x=1<<i;
            if(!(x&N)){
                m|=x;
            }
        }
        return m;
    }
};