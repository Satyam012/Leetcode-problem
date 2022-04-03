class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-2,j=n-1,k;
        if(n<2)return;
        while(i>=0&&nums[i]>=nums[i+1])i--;
        if(i>=0){
            while(j>i){
            if(nums[j]>nums[i])break;
            j--;
            }
            swap(nums[i],nums[j]);
        }
        sort(nums.begin()+i+1,nums.end());
    }
};