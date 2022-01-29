class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int i=0,n=heights.size(),ans=0;
        while(i<n){
            if(st.empty() || heights[st.top()]<=heights[i])st.push(i++);
            else{
                int topIdx=st.top();
                st.pop();
                int s=heights[topIdx]*(st.empty()? i:(i-st.top()-1));
                ans=max(ans,s);
            }
        }
        while(!st.empty()){
            int topIdx=st.top();
            st.pop();
            int s=heights[topIdx]*(st.empty()? i:i-st.top()-1);
            ans=max(ans,s);
        }
        return ans;
    }
};