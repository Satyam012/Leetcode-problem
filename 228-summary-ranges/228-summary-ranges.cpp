class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)return {};
        vector<string>v;
        int prev=nums[0],next=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==next+1)next=nums[i];
            else{
                if(prev==next)v.push_back(to_string(prev));
                else {
                    v.push_back(to_string(prev)+"->"+to_string(next));
                }
                prev=nums[i];
                next=nums[i];
            }
        }
        if(prev==next)v.push_back(to_string(prev));
        else {
            v.push_back(to_string(prev)+"->"+to_string(next));
        }
        return v;
    }
};