class Solution {
public:
    int numRescueBoats(vector<int>& v, int k) {
        deque<int>q;
        sort(v.begin(),v.end());
        for(auto x:v)q.push_back(x);
        int cnt=0;
        while(q.size()>1){
            if(q.front()+q.back()<=k)q.pop_front();
            q.pop_back();
            cnt++;
        }
        if(q.size())cnt++;
        return cnt;
    }
};