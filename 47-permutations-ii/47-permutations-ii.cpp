class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>>v;
    void permute(vector<int>&nums,int l,int n){
        if(l==n-1){
            if(s.find(nums)==s.end()){
                s.insert(nums);
                v.push_back(nums);
            }    
            return;
        }
        for(int i=l;i<n;i++){
            swap(nums[i],nums[l]);
            permute(nums,l+1,n);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        permute(nums,0,n);
        return v;
    }
};