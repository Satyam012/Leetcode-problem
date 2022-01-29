class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int res = 0,start = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            } 
            else {
                if(st.empty()){
                    start = i;
                } 
                else{
                    st.pop();
                    if(st.empty()){
                        res = max(res,i-start);
                    }
                    else{
                        res = max(res,i-st.top());
                    }
                }
        }
              }     
    return res;

    }
};