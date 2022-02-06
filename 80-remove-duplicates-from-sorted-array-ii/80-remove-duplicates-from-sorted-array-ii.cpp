class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,n=nums.size(),j=0,cnt=0,prev=-1;
        while(j<n){
            if(nums[j]==prev)cnt++;
            else{
                prev=nums[j];
                cnt=1;
            }
            if(cnt>2)j++;
            else{
                nums[i++]=nums[j++];
            }
        }
        return i;
    }
};