class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>valid(n+1,1);
        vector<int>count(n+1);
        for(auto &t:trust){
            valid[t[0]]=false;
            count[t[1]]+=1;
        }
        
        for(int i=1;i<=n;i++){
            if(count[i]==n-1 && valid[i]==1)return i;
        }
        return -1;
    }
};