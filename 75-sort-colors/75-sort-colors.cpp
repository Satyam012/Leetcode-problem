class Solution {
public:
    void sortColors(vector<int>&v) {
        int i,j,a=0,b=0;
        for(i=0;i<v.size();i++)
        {
            if(v[i]==0){swap(v[a],v[i]); a++; b=max(a,b);}
            if(v[i]==1){swap(v[b],v[i]); b++;}
        }
    }
};