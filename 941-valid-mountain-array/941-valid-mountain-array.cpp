class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i+1]>arr[i])continue;
            if(arr[i]<arr[i-1] && arr[i+1]<arr[i])continue;
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])cnt++;
            else return false;
        }
        return cnt==1;
    }
};