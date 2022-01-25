class Solution {
public:
    int m,n;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int x,int y){
        if(x<0 || y<0 || x>=m || y>=n)return false;
        return true;
    }
    void dfs(vector<vector<bool>>&sea, vector<vector<int>>&heights, int x,int y){
        if(sea[x][y]==true)return;
        sea[x][y]=1;
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0],dy=y+dir[i][1];
            if(valid(dx,dy) && heights[x][y]<=heights[dx][dy])dfs(sea,heights,dx,dy);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vector<vector<int>>ans;
        
        vector<vector<bool>>left(m,vector<bool>(n,false)),right(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++)dfs(left,heights,i,0);
        for(int j=0;j<n;j++)dfs(left,heights,0,j);
        
        for(int i=0;i<m;i++)dfs(right,heights,i,n-1);
        for(int j=0;j<n;j++)dfs(right,heights,m-1,j);
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(left[i][j] && right[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};