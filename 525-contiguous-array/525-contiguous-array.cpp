class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int s=0;
        map<int,int>m;
        int maxx=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)s--;
            else s++;
            if(m.find(s)!=m.end())
            {
                if(maxx<i-m[s])maxx=i-m[s];
            }
            else m[s]=i;
        }
        
        return maxx;;
    }
};