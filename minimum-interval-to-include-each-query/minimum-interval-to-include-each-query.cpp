class Solution {
public:
    class comp{
        public:
            bool operator()(pair<int,int>&p1,pair<int,int>&p2){
                return p1.first>p2.first;
            }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>ans,que=queries;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq;
        sort(intervals.begin(),intervals.end());
        sort(que.begin(),que.end());
        
        int i=0,n=intervals.size();
        
        unordered_map<int,int>mp;
        for(auto &q:que){
            while(i<n && intervals[i][0]<=q){
                int l=intervals[i][0],r=intervals[i][1],second=intervals[i][1];
                pq.push({r-l+1,second});
                //cout<<r-l+1<<endl;
                i++;
            }
            while(!pq.empty() && pq.top().second<q)pq.pop();
            if(pq.empty())mp[q]=-1;
            else mp[q]=pq.top().first;
        }
        for(auto &q:queries){
            ans.push_back(mp[q]);
        }
        return ans;
    }
};