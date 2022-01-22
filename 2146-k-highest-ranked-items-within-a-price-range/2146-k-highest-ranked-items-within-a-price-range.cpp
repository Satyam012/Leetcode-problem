class Solution {
public:
    bool valid(int x,int y,int m,int n){
        if(x>=0 && y>=0 && x<m && y<n )return true;
        return false;
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pr, vector<int>& start, int k) {
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        vector<vector<int>>v;
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
        int dis=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                if(grid[x][y]==0)continue;
                if(vis[x][y]==1)continue;
                
                vis[x][y]=1;
                
                if(grid[x][y]>=pr[0] && grid[x][y]<=pr[1]){
                    v.push_back({dis,grid[x][y],x,y});
                }
                
                for(auto &d:dir){
                    if(valid(x+d.first,y+d.second,m,n)){
                        q.push({x+d.first,y+d.second});
                    }
                }
            }
            dis++;
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<v.size() && i<k;i++)ans.push_back({v[i][2],v[i][3]});
        return ans;
    }
};