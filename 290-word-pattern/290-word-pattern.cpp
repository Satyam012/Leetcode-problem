class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_set<string>st;
        vector<string>v;
        string str;
        for(auto c:s){
            if(c==' '){
                if(str.length())v.push_back(str);
                str="";
            }
            else str+=c;
        }
        if(str.length())v.push_back(str);
        if(v.size()!=pattern.length())return false;
        
        for(int i=0;i<v.size();i++){
            if(mp[pattern[i]]==""){
                if(st.find(v[i])!=st.end())return false;
                st.insert(v[i]);
                mp[pattern[i]]=v[i];
            }
            else if(mp[pattern[i]]!=v[i])return false;
        }
        return true;
    }
};