class Solution {
public:
    int maxArea(vector<int>& v) {
        int maxx=0,i=0,j=v.size()-1;
        while(i<j)
        {
            maxx=max(maxx,min(v[i],v[j])*(j-i));
            if(v[i]>v[j])j--;
            else i++;
        }
        return maxx;
    }
};