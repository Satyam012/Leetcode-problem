#define ll long long 
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        for(ll i=1;i<=9;i++){
            solve(i,v,low,high);
        }
        sort(v.begin(),v.end());
        return v;
    }
    void solve(ll n,vector<int>&v,int l,int h){
        if(n>h)return;
        if(n>=l)v.push_back(n);
        int rem=n%10;
        if(rem==9)return;
        int s=10*n+rem+1;
        solve(s,v,l,h);
    }
};