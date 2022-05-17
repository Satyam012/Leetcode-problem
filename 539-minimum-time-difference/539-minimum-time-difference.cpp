class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
        for(auto x:timePoints){
            int h=stoi(x.substr(0,2));
            int m=stoi(x.substr(3,2));
            int t=60*h+m;
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        int ans=v[0]+1440-v.back();
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};