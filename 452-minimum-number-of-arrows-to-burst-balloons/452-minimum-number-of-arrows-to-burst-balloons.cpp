class Solution {
public:
    int findMinArrowShots(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[1]<v2[1];
        });
        int cnt=0,z;
        for(auto &x:v){
            if(cnt==0){
                cnt++;
                z=x[1];
            }
            else if(x[0]<=z)continue;
            else{
                z=x[1];
                cnt++;
            }
        }
        return cnt;
    }
};