class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long int cs=0,r=0;
        map<long long int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            if(cs==k)r++;
            if(m.find(cs-k)!=m.end())
            {
                r+=m[cs-k];
            }
            m[cs]++;
        }
        return r;
    }
};