class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;i++){
            int x=i,cnt=0;
            while(x){
                if(x&1)cnt++;
                x>>=1;
            }
            v.push_back(cnt);
        }
        return v;
    }
};