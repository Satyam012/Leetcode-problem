class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto v:accounts){
            int tmp=0;
            for(auto x:v)tmp+=x;
            ans=max(ans,tmp);
        }
        return ans;
    }
};