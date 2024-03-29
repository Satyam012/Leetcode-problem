class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int>mp;
        for(int i=0;i<S.length();i++){
            mp[S[i]]=i;
        }
        int i=0,j=0,k=0;
        vector<int>v;
        while(i<S.length()){
            j=mp[S[i]];
            while(i<=j){
                j=max(j,mp[S[i]]);
                i++;    
            }    
            v.push_back(i-k);
            k=i;
        }
        return v;
    }
};