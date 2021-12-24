class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[](vector<int>v1,vector<int>v2){
            return v1[0]<v2[0];
        });
        vector<vector<int>>ans;
        for(auto x:v){
            if(ans.size()==0){
                ans.push_back(x);
                continue;
            }
            vector<int>vec=ans.back();
            if(vec[1]<x[0])ans.push_back(x);
            else{
                ans.pop_back();
                ans.push_back({vec[0],max(x[1],vec[1])});
            }
        }
        return ans;
    }
};