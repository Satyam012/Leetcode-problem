class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st;
        unordered_map<string,int>indegree;
        unordered_map<string,vector<string>>graph;
        
        for(auto &s:supplies)st.insert(s);
        for(auto &x : recipes)indegree[x] = 0;
        
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(st.find(ingredients[i][j])==st.end()){
                    indegree[recipes[i]]++;
                    graph[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        queue<string>q;
        for(auto &x:indegree){
            if(x.second==0)q.push(x.first);
        }
        vector<string>res;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string top=q.front();
                q.pop();
                res.push_back(top);
                for(auto &x:graph[top]){
                    indegree[x]--;
                    if(indegree[x]==0)q.push(x);
                }
            }
        }
        return res;
    }
};