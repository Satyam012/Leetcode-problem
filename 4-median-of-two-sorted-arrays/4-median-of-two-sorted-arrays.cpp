class Solution {
public:
    
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k){
        int n= arr1.size();
        int m= arr2.size();
        
        int l = min(arr1[0] , arr2[0]) ;
        int r = max(arr1[n - 1] , arr2[m - 1]);
        while(l <= r)
        {
            int mid = (l + r ) / 2;
            int x = upper_bound(arr1.begin(), arr1.end() , mid) - arr1.begin() ;
            int y = upper_bound(arr2.begin(), arr2.end() , mid) - arr2.begin() ;
            
            if(x + y < k )l = mid + 1 ;
            else{
                r = mid - 1 ;
            }
        }
        return l ;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        if(m==0)return 0.0;
        if(n==0){
            int mid=m/2;
            
            if(m%2==1){
                return nums2[mid];
            }    
            return (nums2[mid]+nums2[mid-1])/2.0;
        }
        if((m+n)%2)return kthElement(nums1,nums2,(m+n+1)/2);
        else{
            int x=kthElement(nums1,nums2,(m+n)/2);
            int y=kthElement(nums1,nums2,(m+n)/2+1);
            return (x+y)/2.0;
        }
    }
};