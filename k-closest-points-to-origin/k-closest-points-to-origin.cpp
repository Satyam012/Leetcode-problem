class Solution {
public:
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b) 
        {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& v, int K) {
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        for(auto x:v){
            pq.push(x);
            if(pq.size()>K)pq.pop();
        }
        vector<vector<int>>vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            pq.pop();
        }
        return vec;
    }
};