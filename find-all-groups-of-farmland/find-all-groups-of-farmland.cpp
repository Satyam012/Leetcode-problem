class Solution {
public:
    int x=0,y=0;
    
    void dfs(vector<vector<int>>& land,vector<vector<int>>& vis,int di,int dj,int m,int n){
        if(di>=m || di<0 || dj<0 || dj>=n || vis[di][dj] || land[di][dj]==0)return;
        vis[di][dj]=1;
        x=max(x,di);
        y=max(y,dj);
        dfs(land,vis,di+1,dj,m,n);
        dfs(land,vis,di,dj+1,m,n);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(),n=land[0].size();
        
        vector<vector<int>>ans,vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 && vis[i][j]==0){
                    x=0,y=0;
                    dfs(land,vis,i,j,m,n);
                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
};