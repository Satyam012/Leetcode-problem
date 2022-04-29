class Solution {
public:
    int getMinPoint(vector<int>&v,int x){
        int l=0,h=v.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(v[mid]>=x)h=mid-1;
            else l=mid+1;
        }
        return l;
    }
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& points) {
        vector<int>mp[101];
        for(auto x:r)mp[x[1]].push_back(x[0]);
        for(int i=0;i<101;i++){
            sort(mp[i].begin(),mp[i].end());
        }
        vector<int>ans;
        for(auto x:points){
            int cnt=0;
            for(int i=x[1];i<=100;i++){
                cnt+= mp[i].size() - getMinPoint(mp[i],x[0]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};