class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) 
    {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& v, int K) {
        
        sort(v.begin(),v.end(),compare);
        return vector<vector<int>>(v.begin(), v.begin() + K);
    }
};