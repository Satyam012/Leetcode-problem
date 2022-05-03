class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>s1,s2;
        int n=nums.size(),l=n,h=0;
        for(int i=0;i<n;i++){
            while(!s1.empty()&&nums[s1.top()]>nums[i]){
                l=min(l,s1.top());
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty()&&nums[s2.top()]<nums[i]){
                h=max(h,s2.top());
                s2.pop();
            }
            s2.push(i);
        }
        return h-l>0?h-l+1:0;
    }
};