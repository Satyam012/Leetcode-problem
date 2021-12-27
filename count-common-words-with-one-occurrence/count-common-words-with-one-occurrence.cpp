class Solution {
public:
    int countWords(vector<string>& word1, vector<string>& word2) {
        int cnt=0;
        for(int i=0;i<word1.size();i++){
            string str=word1[i];
            int cnt1=0,cnt2=0;
            
            for(int j=0;j<word1.size();j++){
                if(str==word1[j])cnt1++;
            }
            
            for(int k=0;k<word2.size();k++){
                if(str==word2[k])cnt2++;
            }
            if(cnt1==1 && cnt2==1)cnt++;
        }
        return cnt;
    }
};