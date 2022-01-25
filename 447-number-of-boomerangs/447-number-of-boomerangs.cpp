class Solution {
public:
    long long dis(vector<int>&a,vector<int>&b){
            int dx = a[0] - b[0];
            int dy = a[1] - b[1];
            return dx*dx + dy*dy;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        
        
        
        for(int j=0;j<n;j++){
            unordered_map<int,int>mp;
            for(int k=0;k<n;k++){
                if(j==k)continue;
                int dist=dis(points[k],points[j]);
                mp[dist]++;
            }
            for(auto p:mp){
                int y=p.second;
                ans+=(y*(y-1));
            }
        }
        
        return ans;
    }
};