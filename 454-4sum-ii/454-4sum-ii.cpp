class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int>v;
        int cnt=0;
        map<int,int>mp;
        for(auto x:A){
            for(auto y:B){
                mp[x+y]++;
            }
        }
        for(auto x:C){
            for(auto y:D){
                cnt+=mp[-x-y];
            }
        }
        return cnt;
    }
};