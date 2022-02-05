class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact,digit;
        string ans="";
        for(int i=1;i<=n;i++)digit.push_back(i);
        
        for(int i=1;i<n;i++){
            if(i==1)fact.push_back(i);
            else fact.push_back(fact.back()*i);
        }
        k--;
        while(!fact.empty()){
            int idx=k/fact.back();
            ans+=to_string(digit[idx]);
            digit.erase(digit.begin()+idx);
            k%=fact.back();
            fact.pop_back();
        }
        ans+=to_string(digit[0]);
        return ans;
    }
};