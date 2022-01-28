class WordDictionary {
public:
    class Trie{
        public:
        bool isPresent;
        Trie*child[26];
        Trie(){
            isPresent=false;
            for(int i=0;i<26;i++)child[i]=NULL;
        }
    };
    Trie*root=new Trie();
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie*tmp=root;
        for(auto c:word){
            if(tmp->child[c-'a']==NULL)tmp->child[c-'a']=new Trie();
            tmp=tmp->child[c-'a'];
        }
        tmp->isPresent=true;
    }
    
    bool search(string word) {
        Trie*tmp=root;
        queue<Trie*>q;
        q.push(tmp);
        
        for(auto c:word){
            int sz=q.size();
            bool flag=false;
            
            while(sz--){
                Trie*top=q.front();
                q.pop();
                if(c=='.'){
                    for(int i=0;i<26;i++){
                        if(top->child[i]!=NULL)q.push(top->child[i]);
                        flag=true;
                    }
                }
                else if(top->child[c-'a']!= NULL){
                    flag=true;
                    q.push(top->child[c-'a']);
                }
            }
            if(flag==false)return false;
        }
        while(!q.empty()){
            Trie*top=q.front();
            q.pop();
            if(top->isPresent==true)return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */