class Solution {
public:
    int racecar(int target) {
        int level=0;
        unordered_set<string>st;
        queue<pair<int,int>>q;
        q.push({0,1});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p= q.front();
                q.pop();
                if(p.first==target)return level;
                string key=to_string(p.first)+" "+to_string(p.second);
                if(st.find(key)!=st.end())continue;
                st.insert(key);
                
                int newVal=p.first+p.second;
                if(newVal>0 && newVal<target*2){
                    q.push({newVal,2*p.second});
                }
                if(p.second>0)q.push({p.first,-1});
                else q.push({p.first,1});
            }
            level++;
        }
        return 0;
    }
};