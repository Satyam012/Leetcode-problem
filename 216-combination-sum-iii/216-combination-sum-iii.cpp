class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        int s1=0,s2=0;
        for(int i=0;i<k;i++){
            s1+=(i+1);
            s2+=(9-i);
        }    
        if(s1>n || s2<n)return {};
        vector<int>v;
        f(v,1,k,0,n);
        return ans;
    }
    void f(vector<int>v,int l,int k,int cur,int s){
        if(cur>s || v.size()>k)return;
        if(v.size()==k && cur==s){
            ans.push_back(v);
            return;
        }
        for(int i=l;i<=9;i++){
            v.push_back(i);
            f(v,i+1,k,cur+i,s);
            v.pop_back();
        }    
    }
};