class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cnt=1,num=1;
        unordered_map<int,int>mp;
        while(1){
            int rem=num%k;
            if(rem==0)return cnt;
            if(mp[rem]>0)return -1;
            else mp[rem]=1;
            num=num*10+1;
            num=num%k;
            cnt++;
        }
        return -1;
    }
};