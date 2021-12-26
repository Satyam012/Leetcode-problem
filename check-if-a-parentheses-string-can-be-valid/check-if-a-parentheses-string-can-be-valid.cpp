class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2)return false;
        int free=0,open=0,close=0;
        
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0')free++;
            else if(s[i]=='(')open++;
            else close++;
            if(close>open+free)return 0;
        }
        free=0,open=0,close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(locked[i]=='0')free++;
            else if(s[i]=='(')open++;
            else close++;
            if(open>close+free)return 0;
        }
        return 1;
    }
};