class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0,m=v1.length(),n=v2.length(),x,y;
        while(i<m || j<n){
            string s1,s2;
            while(i<m && v1[i]!='.')s1+=v1[i++];
            while(j<n && v2[j]!='.')s2+=v2[j++];
            x=s1.length()==0?0:stoi(s1);
            y=s2.length()==0?0:stoi(s2);
            if(x<y)return -1;
            else if(x>y)return 1;
            i++;j++;
        }
        return 0;
    }
};