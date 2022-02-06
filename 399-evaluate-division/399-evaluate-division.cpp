class Solution {
public:
    map<string,vector<string>>mp;
    map<vector<string>,double>data;
            
    double dfs(string up,string down,unordered_set<string>vis){
        if(data.find({up,down})!=data.end())return data[{up,down}];
       
        for(auto x:mp[up]){
            if(vis.find(x)==vis.end()){
                vis.insert(x);
                double tmp=dfs(x,down,vis);
                if(tmp)return tmp*data[{up,x}];
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& q) {
        
        for(int i=0;i<eq.size();i++){
            mp[eq[i][0]].push_back(eq[i][1]);
            data[eq[i]]=values[i];
            
            if(values[i]!=0){
                data[{eq[i][1],eq[i][0]}]=1/values[i];
                mp[eq[i][1]].push_back(eq[i][0]);
            }
        }
        vector<double>ans;
        for(auto x:q){
            unordered_set<string>vis;
            double val=dfs(x[0],x[1],vis);

            if(val)ans.push_back(val);
            else ans.push_back(-1);
        }
        return ans;
    }
};