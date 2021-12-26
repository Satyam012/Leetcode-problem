#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        unordered_map<ll,ll>sum,cnt;
        vector<ll>ans(n);
        
        // [10,5,10,10]
        
        for(int i=0;i<n;i++){
            ll val=arr[i];
            ll tmp=i*cnt[val]-sum[val];
            sum[val]+=i;
            cnt[val]++;
            ans[i]+=tmp;
        }
        sum.clear();
        cnt.clear();
        
        for(int i=n-1;i>=0;i--){
            ll val=arr[i];
            ll tmp=sum[val]-i*cnt[val];
            sum[val]+=i;
            cnt[val]++;
            ans[i]+=tmp;
        }
        return ans;
    }
};