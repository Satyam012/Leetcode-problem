class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j&& s[i]==s[j]){
            i++;
            j--;
        }
        if(i>=j)return true;
        return palin(s,i+1,j)||palin(s,i,j-1);
    }
    bool palin(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
};