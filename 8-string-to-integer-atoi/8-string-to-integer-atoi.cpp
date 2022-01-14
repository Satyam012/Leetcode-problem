class Solution {
public:
    int myAtoi(string str) {
        long int x=0,z=1,i;
        for(i=0;i<str.length();i++){
            if(str[i]==' ')continue;
            if(str[i]=='-'){z=-1; i++;}
            else if(str[i]=='+'){z=1; i++;}
            while(str[i]>='0'&&str[i]<='9'){
                x=x*10+str[i++]-'0';
                if(x*z>INT_MAX)return INT_MAX;
                else if(x*z<INT_MIN)return INT_MIN;
            } 
            return x*z;      
        }
        return x*z;         
    }
};