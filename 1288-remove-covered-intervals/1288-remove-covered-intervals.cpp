class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){ 
            if(a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0]; 
        });
        
        int left = intervals[0][0];
        int right = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (left <= intervals[i][0] && right >= intervals[i][1]) res++;
            right=max(right,intervals[i][1]);
        }
        return intervals.size() - res;
            
    }
};