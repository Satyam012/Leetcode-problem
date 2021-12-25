class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.length()-1,cnt=0;
        while(j>=0 &&s[j]==' ')j--;
        while(j>=0 && s[j]!=' '){
            cnt++;
            j--;
        }
        return cnt;
    }
};