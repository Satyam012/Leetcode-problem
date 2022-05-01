class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i,j;
        i=s.length()-1;
        j=t.length()-1;
        int x=0,y=0;
        while(i>=0||j>=0)
        {
            if(i>=0&&s[i]=='#')x++;
            if(j>=0&&t[j]=='#')y++;
            
            while(x>0&&i>=0)
            {    
            while(x>0&&i>0)
            {
                i--;
                if(s[i]=='#')x++;
                else x--;
            }
            i--;
            if(i>=0&&s[i]=='#')x++;    
            } 
            
            while(y>0&&j>=0)
            {    
            while(y>0&&j>0)
            {
                j--;
                if(t[j]=='#')y++;
                else y--;
            }
            j--;
            if(j>=0&&t[j]=='#')y++;        
            }
            
            if(i<0&&j<0)return true;
            if(i<0&&j>=0)return false;
            if(i>=0&&j<0)return false;
            if(s[i]==t[j]){i--; j--; continue;}
            else return false;
        }
        if(i<0&&j<0)return true;
        else return false;
        
    }
};