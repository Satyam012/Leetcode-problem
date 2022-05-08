class Solution {
public:
    vector<int>parent;
    void _union(int x,int y){
        parent[find(y)]=parent[find(x)];
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    int largestComponentSize(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        parent.resize(maxVal+1);
        for(int i=0;i<=maxVal;i++)parent[i]=i;
        // 2 5 6 7 9 10
        
        
        for(auto &val:nums){
            for(int i=2;i<=sqrt(val);i++){
                if(val%i==0){
                    _union(val/i,val);
                    _union(i,val);
                }
            }
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:nums){
            ans=max(ans,++mp[parent[find(i)]]);
        }
        return ans;
    }
};