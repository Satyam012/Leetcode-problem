class Solution {
public:
    bool valid(vector<int>&nums,int n,int max){
        int sum=0;
        for(auto x:nums){
            sum+=x;
            if(sum>max){
                sum=x;
                n--;
                if(n<0)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l=0,h=0;
        for(auto x:nums){
            l=max(l,(long long)x);
            h+=x;
        }
        while(l<h){
            long long mid=(l+h)/2;
            if(valid(nums,m-1,mid))h=mid;
            else l=mid+1;
        }
        return l;
    }
};