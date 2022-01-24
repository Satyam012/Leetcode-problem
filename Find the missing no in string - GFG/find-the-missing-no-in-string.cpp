// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    for(int i=1;i<=6;i++){
        vector<int>v;
        int j=0,num=stoi(str.substr(0,i)),num2=0;
        v.push_back(num);
        j=i;
        while(j<str.length()){
            while(j<str.length() && num2<=num){
                num2=num2*10+(str[j]-'0');
                j++;
            }
            v.push_back(num2);
            num=num2;
            num2=0;
        }
        int cnt=0,ans=-1;
        for(j=1;j<v.size();j++){
            if(v[j]-v[j-1]>2 || v[j]<=v[j-1])break;
            if(v[j]-v[j-1]==2){
                if(cnt==1)break;
                cnt++;
                ans=(v[j]+v[j-1])/2;
            }
        }
        if(j==v.size() && cnt==1 && v.size()>1)return ans;
    }
    return -1;
}