class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag=0,a=0,b=0;
        if(word[0]>='A'&&word[0]<='Z')flag=true;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A'&&word[i]<='Z')b++;
            else a++;
        }
        if(b==word.length()||a==word.length()||(b==1&&flag==1))return true;
        return false;
    }
};