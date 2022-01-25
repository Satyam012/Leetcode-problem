class Solution {
public:
    bool valid(int id,vector<int>&v){
        for(int j=id;j<v.size();j++){
            if(v[j]==1)return false;
        }
        return true;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            bool flag=valid(i+1,grid[i]);
            
            if(flag==false){
                int j=i+1;
                while(j<m){
                    if(valid(i+1,grid[j]))break;
                    j++;
                }
                if(j==m)return -1;
                else{
                    ans+=j-i;
                    while(j>i){
                        swap(grid[j],grid[j-1]);
                        j--;
                    }
                }
            }
        }
        return ans;
    }
};