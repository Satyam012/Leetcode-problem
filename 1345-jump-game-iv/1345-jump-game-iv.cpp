class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        queue<int>q;
        vector<bool>dp(n,false);
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<arr.size();i++)mp[arr[i]].push_back(i);
        
        q.push(0);
        int ans=0;
        dp[0]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int id=q.front();
                q.pop();
                if(id==n-1)return ans;
                
                vector<int> &index=mp[arr[id]];
                index.push_back(id-1);
                index.push_back(id+1);
                
                for(auto x:index){
                    if(x>=0 && x<n && dp[x]==false){
                        q.push(x);
                        dp[x]=true;
                    }
                }
                index.clear();
            }
            ans++;
        }
        return ans;
    }
};