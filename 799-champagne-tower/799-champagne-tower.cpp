class Solution {
public:
    double champagneTower(int p, int r, int c) {
        vector<vector<double>>v(101,vector<double>(101,0));
        int i,j;
        v[0][0]=p;
        for(i=0;i<=r;i++){
            for(j=0;j<=i;j++){
                if(v[i][j]>1.0){
                    v[i+1][j]+=(v[i][j]-1)/2.0;
                    v[i+1][j+1]+=(v[i][j]-1)/2.0;
                    v[i][j]=1.0;
                }
            }
        }
        return v[r][c];
    }
};