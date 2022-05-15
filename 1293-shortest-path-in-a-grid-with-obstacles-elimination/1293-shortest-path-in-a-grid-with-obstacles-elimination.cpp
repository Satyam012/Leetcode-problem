class Solution {
public:
    int dir[4][2]={0,1,1,0,0,-1,-1,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        
        queue<vector<int>>q;
        q.push({0,0,0,k});
        
        while(!q.empty()){

            auto v=q.front();
            q.pop();

            int x=v[0], y=v[1];

            if(x<0 || x>=m || y<0 || y>=n){
                continue;
            }
            
            if(x==m-1 && y==n-1)return v[2];
            
            if(grid[x][y]==1){
                if(v[3]==0)continue;
                v[3]--;   
            }
            
            if(vis[x][y]>=v[3])continue;
            vis[x][y]=v[3];
            
            for(int i=0;i<4;i++){
                q.push({x+dir[i][0],y+dir[i][1],v[2]+1,v[3]});
            }

        }
        return -1;
    }
};