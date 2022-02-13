class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vc;
        vector<int>v;
        test(nums,0,vc,v);
        return vc;
    }
    void test(vector<int>&nums,int i,vector<vector<int>>&vc,vector<int>&v)
    {
        vc.push_back(v);
        for(int j=i;j<nums.size();j++)
        {
            v.push_back(nums[j]);
            test(nums,j+1,vc,v);
            v.pop_back();
        }
    }
};