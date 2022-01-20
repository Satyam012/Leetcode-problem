class Solution {
public:
    vector<int> getRow(int id) {
        vector<vector<int>>v(id+1,vector<int>(id+1));
        v[0][0]=1;
        for(int i=1;i<=id;i++){
            v[i][0]=1;
            for(int j=1;j<=i;j++){
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        return v[id];
    }
};