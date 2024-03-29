class Solution {
public:
    int scoreOfParentheses(string S) {
        int res,ans=0;
        stack<int>st;
        for(auto c:S){
            if(c=='(')st.push(-1);  
            else{
                if(st.top()==-1){//case-1 ()
                    st.pop();
                    st.push(1); 
                }    
                else{                         
                    int x=st.top();
                    st.pop();
                    while(!st.empty() && st.top()!=-1){ //case-2 A+B+C
                        x+=st.top();
                        st.pop();
                    }
                    if(!st.empty() && st.top()==-1){
                        st.pop();
                        st.push(2*x);
                    }
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};