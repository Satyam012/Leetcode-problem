class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int>ans,dp;
        ans.push_back(1);
        dp.push_back(obs[0]);
        for(int i=1;i<obs.size();i++){
            auto it=upper_bound(dp.begin(),dp.end(),obs[i]);
            if(it==dp.end()){
                dp.push_back(obs[i]);
                ans.push_back(dp.size());
            }
            else{
                *it=obs[i];
                int idx=(it-dp.begin())+1;
                ans.push_back(idx);
            }
            
        }
        return ans;
    }
};