class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j=0,sm=0,x=0;
        for(i=0;i<gas.size();i++){
            x+=gas[i]-cost[i];
            if(x<0){
                j=i+1;
                sm+=x;
                x=0;
            }
        }
        if(sm+x<0)return -1;
        return (j%cost.size());
    }
};