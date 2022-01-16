class Solution {
public:
    int maxDistToClosest(vector<int>&v) {
        int i=0,j=-1,res=0;
        for(i=0;i<v.size();i++){
            if(v[i]==1){
                if(j==-1)res=i;
                else res=max(res,(i-j)/2);
                j=i;
            }
        }
        i=v.size()-j-1;
        res=max(res,i);
        return res;
    }
};