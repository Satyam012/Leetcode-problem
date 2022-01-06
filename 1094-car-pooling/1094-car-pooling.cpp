class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int c) {
        int x=0,i;
        for(auto z:trips){
            x=max(x,z[2]);
        }
        vector<int>a(x+1);
        for(auto x:trips){
            a[x[1]]+=x[0];
            a[x[2]]-=x[0];
        }
        if(a[0]>c)return false;
        for(i=1;i<=x;i++){a[i]+=a[i-1]; if(a[i]>c)return false;}
        return true;
    }
};