class Solution {
public:
    class Trie{
        public:
        Trie* child[2];
        Trie(){
            this->child[0]=NULL;
            this->child[1]=NULL;
        }
    };
    Trie* head=new Trie();
    
    void insert(int num){
        Trie*root=head;
        for(int i=31;i>=0;i--){
            bool bit= num & 1<<i;
            if(root->child[bit]==NULL)root->child[bit]=new Trie();
            root=root->child[bit];
        }
    }
    
    int maxXor(int num){
        Trie* root=head;
        int ans=0;
        for(int i=31;i>=0;i--){
            bool bit= num & 1<<i;
            if(root->child[1-bit]==NULL){
                root=root->child[bit];
            }
            else{
                ans+=(1<<i);
                root=root->child[1-bit];
            }    
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto x:nums)insert(x);
        for(auto x:nums){
            ans=max(ans,maxXor(x));
        }
        return ans;
    }
};