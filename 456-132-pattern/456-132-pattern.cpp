class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size(),c=INT_MIN,b=arr[n-1];
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<c)return true;
            while(!st.empty() && arr[i]>st.top()){
                c=st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return false;
    }
};