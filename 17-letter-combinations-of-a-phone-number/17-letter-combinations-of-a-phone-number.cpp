class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string d) {
        if(d.length()==0)return {};
        vector<string>ans;
        f(0,d,ans,"");
        return ans;
    }
    void f(int l,string &d,vector<string>&ans,string s){
        if(l==d.length())ans.push_back(s);
        else for(auto c:pad[d[l]-'0'])f(l+1,d,ans,s+c);
    }
};