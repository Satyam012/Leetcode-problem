class Solution {
public:
    int titleToNumber(string s) {
        long int ans=0;
        for(auto c:s){
            ans=ans*26+c-'A'+1;
        }
        return ans;
    }
    
};