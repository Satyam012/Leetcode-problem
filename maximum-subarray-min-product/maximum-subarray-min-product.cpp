#define ll long long
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        ll ans=0,i=0,n=nums.size(),mod=1e9+7;
        stack<ll>st;
        vector<ll>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=nums[i]+dp[i-1];
        }
        
        while(i<n){
            if(st.empty() || nums[st.top()]<=nums[i])st.push(i++);
            else{
                ll top=st.top();
                st.pop();
                ll sum=nums[top]*( st.empty()? dp[i-1] : (dp[i-1]-dp[st.top()]));
            
                ans=ans>sum?ans:sum;
            }
        }
        
        while(!st.empty()){
            ll top=st.top();
            st.pop();
            ll sum=nums[top]*( st.empty()? dp[i-1] : (dp[i-1]-dp[st.top()]));
            ans=ans>sum?ans:sum;
        }
        return ans%mod;
    }
};