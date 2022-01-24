// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int k,string str,string &smax,int id){
        if(k==0 || id>=str.length())return;
        char maxVal=str[id];
        
        for(int i=id+1;i<str.length();i++){
            if(str[i]>maxVal)maxVal=str[i];
        }
        
        if (maxVal != str[id])--k;
        
        for(int j=str.length()-1;j>=id;j--){
            if(maxVal==str[j]){
                swap(str[j],str[id]);
                smax=max(smax,str);
                solve(k,str,smax,id+1);
                swap(str[j],str[id]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string smax=str;
        solve(k,str,smax,0);
        return smax;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends