class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>v;
        for(auto x:ops){
            if(x=="+"){
                int sz=v.size()-1;
                v.push_back(v[sz]+v[sz-1]);
            } else if(x=="D"){
                v.push_back(v.back()*2);
            } else if(x=="C"){
                v.pop_back();
            } else{
                v.push_back(stoi(x));
            }
        }
        int ans=0;
        for(auto x:v)ans+=x;
        return ans;
    }
};