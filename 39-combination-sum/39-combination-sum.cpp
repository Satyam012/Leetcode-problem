class Solution {
public:
    vector<vector<int>>vec;
    vector<vector<int>> combinationSum(vector<int>&can, int s) {
        //sort(can.begin(),can.end());
        vector<int>v;
        test(0,can.size(),can,s,v);
        return vec;
    }
    void test(int i,int n,vector<int>&can,int s,vector<int>&v){
        if(s==0){
            vec.push_back(v);
            return;
        }
        if(s<0||i>=n)return;
        for(int j=i;j<n;j++){
            v.push_back(can[j]);
            test(j,n,can,s-can[j],v);
            v.pop_back();
        }
    }
};