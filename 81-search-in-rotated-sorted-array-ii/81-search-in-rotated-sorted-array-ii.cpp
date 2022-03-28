class Solution {
public:
    bool search(vector<int>& nums, int &target) {
        int n=nums.size(),l=0,h=n-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target)return 1;
            if(nums[mid]==nums[l] && nums[mid]==nums[h])l++,h--;
            else if(nums[mid]>=nums[l]){
                if(target<=nums[mid]&&target>=nums[l])h=mid-1;
                else l=mid+1;
            }
            else{
                if(target<=nums[h]&&target>=nums[mid])l=mid+1;
                else h=mid-1;
            }
        }
        return 0;
    }
};