class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        for(int i=0;i<sz;i++){
            if(n==0)return true;
            if(flowerbed[i]==0){
                int x=i==0 ? 0:flowerbed[i-1];
                int y=i==sz-1 ? 0:flowerbed[i+1];
                if(x==0&&y==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        if(n==0)return true;
        return false;
    }
};