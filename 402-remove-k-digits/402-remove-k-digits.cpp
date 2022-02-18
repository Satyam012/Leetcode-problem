class Solution {
public:
    string removeKdigits(string num, int k) {
        int i=0,j=i+1;
        string s="";
        for(char c:num)
        {
            while(s.length()&&s.back()>c&&k>0)
            {
                s.pop_back();
                k--;
            }
            if(s.length()||c!='0')s.push_back(c);
        }
        while(s.length()&&k--)
        {
            s.pop_back();
        }
        return s.empty()?"0":s;
    }
};