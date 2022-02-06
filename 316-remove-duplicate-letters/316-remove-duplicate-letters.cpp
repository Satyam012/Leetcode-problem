class Solution {
public:
    string removeDuplicateLetters(string s) {
        int index[26];
        vector<bool>vis(26);
        string str;
        for(int i=0;i<s.length();i++)index[s[i]-'a']=i;
        for(int i=0;i<s.length();i++){
            if(vis[s[i]-'a'])continue;
            vis[s[i]-'a']=1;    
            while(!str.empty() && str.back()>s[i] && index[str.back()-'a']>i){
                vis[str.back()-'a']=0;
                str.pop_back();
            }    
            str.push_back(s[i]);
        }
        return str;
    }
};