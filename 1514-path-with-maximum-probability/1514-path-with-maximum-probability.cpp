class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int start, int end){
        vector<double>pb(n,0);
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],p[i]});
            adj[edges[i][1]].push_back({edges[i][0],p[i]});
        }
        
        queue<pair<int,double>>q;
        q.push({start,1});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto x:adj[p.first]){
                if(p.second*x.second>pb[x.first]){
                    pb[x.first]=p.second*x.second;
                    q.push({x.first,pb[x.first]});
                }
            }
        }
        
        return pb[end];
    }
};