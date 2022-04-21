class MyHashSet {
public:
    int mod=10007;
    vector<list<int>>table;
    MyHashSet() {
        table.resize(mod);
    }
    
    list<int>::iterator search(int key){
        int idx=key%mod;
        return find(table[idx].begin(),table[idx].end(),key);
    }
    
    void add(int key) {
        int idx=key%mod;
        if(search(key)==table[idx].end())table[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx=key%mod;
        auto it=search(key);
        if(it!=table[idx].end()){
            table[idx].erase(it);
        }    
    }
    
    bool contains(int key) {
        int idx=key%mod;
        if(search(key)!=table[idx].end())return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */