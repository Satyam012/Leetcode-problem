class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),[](vector<int>v1,vector<int>v2){
            if(v1[0]!=v2[0])return v1[0]<v2[0];
            return v1[1]>v2[0];
        });
        vector<bool>vis(v.size(),true);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(vis[j]==false)continue;
                if(v[i][1]>=v[j][1])vis[j]=false;
                else break;
            }
        }    
        for(int i=0;i<v.size();i++)if(vis[i])cnt++;
        return cnt;
    }
};