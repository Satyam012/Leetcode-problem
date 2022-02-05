class Solution {
public:
    vector<vector<int>>vec;
    int n;
    vector<int>cand;
    vector<vector<int>> combinationSum2(vector<int>&can, int s) {
        sort(can.begin(),can.end());
        vector<int>v;
        n=can.size();
        cand=can;
        test(0,s,v);
        return vec;
    }
    void test(int i,int s,vector<int>v){
        if(s==0){
            vec.push_back(v);
            return;
        }
        if(s<0||i>=n)return;
        for(int j=i;j<n;j++){
            if(j>i && cand[j]==cand[j-1]) continue;
            v.push_back(cand[j]);
            test(j+1,s-cand[j],v);
            v.pop_back();
        }
    }    
};