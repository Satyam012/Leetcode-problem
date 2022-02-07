class Solution {
public:
    char findTheDifference(string s, string t) {
        int dp[26]={};
        for(auto c:t)dp[c-'a']++;
        for(auto c:s)dp[c-'a']--;
        for(int i=0;i<26;i++){
            if(dp[i])return 'a'+i;
        }
        return 'a';
    }
};