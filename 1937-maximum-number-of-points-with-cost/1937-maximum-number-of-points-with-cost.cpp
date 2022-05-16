#define max(aa, bb) (aa > bb ? aa:bb)
class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& point) {
        
        long long m=point.size(),n=point[0].size();
        vector<long long>points;
        
        long long ans=0;
        for(int j=0;j<n;j++){
            points.push_back(point[0][j]);
            ans=max(ans,points[j]);
        }
        
        
        for(int i=1;i<m;i++){
            long long left[n],right[n];
            
            for(int l=0;l<n;l++){
                if(l==0)left[l]=points[l];
                else left[l]=max(points[l],left[l-1]-1);
            }
            for(int l=n-1;l>=0;l--){
                if(l==n-1)right[l]=points[l];
                else right[l]=max(points[l],right[l+1]-1);
            }
            for(int j=0;j<n;j++){
                points[j]=point[i][j]+max(left[j],right[j]);
                ans=max(ans,points[j]);
            }
        }
        return ans;
    }
};