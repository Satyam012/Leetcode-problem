class Solution {
public:
    vector<vector<string>>vec;
    int n;
    
    vector<vector<string>> partition(string s) {
        vector<string>v;
        n=s.length();
        if(n==0)return vec;
        dfs(s,0,v);
        return vec;
    }
    
    void dfs(string s,int idx,vector<string>&v)
    {
        if(idx==n)vec.push_back(v);
        else{
        for(int i=idx;i<n;i++)
            {
                if(palindrome(idx,i,s))
                {
                    v.push_back(s.substr(idx,i-idx+1));
                    dfs(s,i+1,v);
                    v.pop_back();
                }
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