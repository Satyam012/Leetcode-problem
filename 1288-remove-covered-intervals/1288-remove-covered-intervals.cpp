class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),[](vector<int>v1,vector<int>v2){
            if(v1[0]!=v2[0])return v1[0]>v2[0];
            return v1[1]<v2[1];
        });
        int cnt=0;
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i][0]>=v[j][0] && v[i][1]<=v[j][1]){
                    cnt++;
                    break;
                }
            }
        }
        return v.size()-cnt;
    }
};