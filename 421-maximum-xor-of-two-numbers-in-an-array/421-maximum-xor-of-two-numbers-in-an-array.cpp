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
                ans+=pow(2,i);
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






// class TrieNode {
//     public:
//         TrieNode *child[2];

//         TrieNode(){
//             this->child[0] = NULL; // 0 bit
//             this->child[1] = NULL; // 1 bit
//         }
// };
// class Solution {
// public:
//     TrieNode* newNode = new TrieNode();
    
//     void insert(int x){
//         TrieNode* t = newNode;
//         bitset<32> bs(x); // Bits of x are stored in bs
        
//         for(int i=31; i>=0; i--){
//             // Create one if the node doesn't exist
//             if(!t->child[bs[i]]) t->child[bs[i]] = new TrieNode();
//             t = t->child[bs[i]];
//         }
//     }
//     int maxXor(int a){
//         TrieNode* t = newNode;
//         bitset<32> bs(a);
//         int ans = 0;
//         for(int i=31; i>=0; i--){
//             if(!t->child[!bs[i]]){
//                 ans += 0 * pow(2, i);
//                 t = t->child[bs[i]];
//             }else{
//                 ans += 1 * pow(2, i);
//                 t = t->child[!bs[i]];
//             }
//         }
//         return ans;
//     }
//     int findMaximumXOR(vector<int>& nums) {
//         for(auto i: nums) insert(i);
        
//         int ans = 0;
//         for(auto i: nums){
//             int a = maxXor(i);
//             ans = max(ans, a);
//         }
//         return ans;
//     }
// };