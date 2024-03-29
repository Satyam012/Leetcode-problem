class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]==')'){
                if(s[i]=='('||st.empty())st.push(i);
                else if(s[st.top()]=='(')st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};