class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        vector<int>v;
        for(auto &x:grid){
            if(x[0]==1){
                for(auto &y:x){
                    y=1-y;
                }
            }
            if(v.size()==0)v=x;
            else if(v!=x)return false;
        }
        return true;
    }
};
