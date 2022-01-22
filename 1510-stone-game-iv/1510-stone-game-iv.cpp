class Solution {
public:
    vector<int>dp;
    bool solve(int n){
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i)==0){
                dp[n]=1;
                return 1;
            }    
        }
        dp[n]=0;
        return 0;
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};