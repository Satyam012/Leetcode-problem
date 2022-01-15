class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        queue<int>q;
        vector<bool>dp(n,false);
        unordered_map<int,vector<int>>mp;
        unordered_set<int>st;
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
                
                if(id>0 && dp[id-1]==false){
                    q.push(id-1);
                    dp[id-1]=true;
                }
                if(id<n-1 && dp[id+1]==false){
                    q.push(id+1);
                    dp[id+1]=true;
                }
                if(st.find(arr[id])!=st.end())continue;
                st.insert(arr[id]);
                for(auto &x:mp[arr[id]]){
                    if(dp[x]==false){
                        q.push(x);
                        dp[x]=true;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};