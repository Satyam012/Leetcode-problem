// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string s,int k){
        long long i=0,j=0,ans=0,cnt[26]={0};
        for(int j=0;j<s.length();j++){
            if(cnt[s[j]-'a']==0)k--;
            cnt[s[j]-'a']++;
            while(k<0){
                if(cnt[s[i]-'a']==1)k++;
                cnt[s[i]-'a']--;
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return solve(s,k)-solve(s,k-1);
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends