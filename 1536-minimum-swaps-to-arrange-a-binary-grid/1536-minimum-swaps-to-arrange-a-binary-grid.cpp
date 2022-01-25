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
        vector<int>count(m);
        
        for(int i=0;i<m;i++){
            int cnt=0,j=n-1;
            while(j>=0 && grid[i][j]==0){
                cnt++;
                j--;
            }
            count[i]=cnt;
        }
        
        for(int i=0;i<m;i++){
            if(count[i]>=n-i-1)continue;
            
            int j=i+1;
            while(j<m &&count[j]<n-i-1)j++;
                
            if(j==m)return -1;
            else{
                ans+=j-i;
                while(j>i){
                    swap(count[j],count[j-1]);
                    j--;
                }
            }
            
        }
        return ans;
    }
};