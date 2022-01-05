class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>vec;
        vector<string>v;
        if(s.length()==0)return vec;
        dfs(s,0,s.length(),vec,v);
        return vec;
    }
    
    void dfs(string s,int idx,int n,vector<vector<string>>&vec,vector<string>&v)
    {
        if(idx==n){vec.push_back(v);return;}
        for(int i=idx;i<n;i++)
        {
            if(palindrome(idx,i,s))
            {
                v.push_back(s.substr(idx,i-idx+1));
                dfs(s,i+1,s.length(),vec,v);
                v.pop_back();
            }
        }
    }
    bool palindrome(int l,int h,string s)
    {
        while(l<=h)
        {
            if(s[l++]!=s[h--])return false;
        }
        return true;
    }
};