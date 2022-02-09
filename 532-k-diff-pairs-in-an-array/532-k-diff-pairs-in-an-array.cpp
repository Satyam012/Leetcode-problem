class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        map<int,int>mp;
        for(auto x:nums)mp[x]++;
        if(k==0){
            for(auto x:mp){
                if(x.second>1)cnt++;
            }
        }
        else{
            for(auto x:mp){
                if(mp[x.first-k]!=0)cnt++;
            }
        }
        return cnt;
    }
};