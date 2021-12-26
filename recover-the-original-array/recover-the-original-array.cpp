// class Solution {
// public:
//     //multiset<int>arr;
    
//     bool valid(multiset<int>arr,int k,vector<int>&res){
//         if(k%2 || k==0)return false;
        
//         while(!arr.empty()){
//             auto it=arr.begin();
//             int low=*it;
//             int high=low+k;
//             arr.erase(it);
//             if(arr.find(high)!=arr.end()){
//                 res.push_back((low+high)/2);
//                 arr.erase(arr.find(high));
//             }
//             else return false;
//         }
//         return true;
//     }
//     vector<int> recoverArray(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         multiset<int>arr(nums.begin(),nums.end());
        
//         for(int i=1;i<nums.size();i++){
//             int k=nums[i]-nums[0];
//             vector<int>res;
//             if(valid(arr,k,res))return res;
//         }
//         return {};
//     }
// };
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define F first
#define S second
#define all(x) begin(x),end(x)

class Solution {
public:
	vector<int> canMakeIt(multiset<int> st, int k) {
		if (k <= 0)
			return { -1};
		vector<int> ans;
		while (st.size() > 0) {
			auto it = st.begin();
			int val = *it;
			int org = val + k;
			st.erase(st.find(val));
			if (st.find(org + k) != st.end()) {
				ans.push_back(org);
				st.erase(st.find(org + k));
			}
			else
				return { -1};
		}
		return ans;
	}

	vector<int> recoverArray(vector<int>& nums) {
		sort(all(nums));
		multiset<int> st(all(nums));
		int smallest = nums[0];
		for (int j = 1; j < nums.size(); ++j) {
			int addi = smallest + nums[j];
			if (addi % 2 == 0) {
				int org = addi / 2;
				int k = nums[j] - org;
				vector<int> ans = canMakeIt(st, k);
				if (ans[0] != -1)
					return ans;
			}
		}
		return { -1};
	}
};