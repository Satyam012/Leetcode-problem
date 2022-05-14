class Solution {
public:
    class comp{
        public:
            bool operator()(const pair<int,int>p1,const pair<int,int>p2){
                return p1.first>p2.first;
            }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int s) {
        vector<int>dis(n+1,1e7);
        vector<int>vis(n+1);
        vector<pair<int,int>>adj[n+1];
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        pq.push({0,s});
        
        dis[s]=0;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first,node=p.second;
            if(vis[node]==1)continue;
            vis[node]=1;
            for(auto x:adj[node]){
                if(dis[x.first]>dis[node]+x.second){
                    dis[x.first]=dis[node]+x.second;
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==s)continue;
            ans=max(ans,dis[i]);
        }
        return ans==1e7 ? -1:ans;
    }
};