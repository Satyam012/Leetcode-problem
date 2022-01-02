class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt=0,sixty=0;
        map<int,int>mp;
        for(auto x:time){
            x%=60;
            if(x==0)sixty++;
            cnt+=mp[60-x];
            mp[x]++;
        }
        return cnt+(sixty*(sixty-1)/2);
    }
};