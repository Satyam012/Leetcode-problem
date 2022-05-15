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

            int xCoordinate=v[0], yCoordinate=v[1];

            if(xCoordinate<0 || xCoordinate>=m || yCoordinate<0 || yCoordinate>=n){
                continue;
            }
            
            if(xCoordinate==m-1 && yCoordinate==n-1)return v[2];
            
            if(grid[xCoordinate][yCoordinate]==1){
                if(v[3]==0)continue;
                v[3]--;   
            }
            
            if(vis[xCoordinate][yCoordinate]>=v[3])continue;
            vis[xCoordinate][yCoordinate]=v[3];
            
            for(int i=0;i<4;i++){
                q.push({xCoordinate+dir[i][0],yCoordinate+dir[i][1],v[2]+1,v[3]});
            }

        }
        return -1;
    }
};