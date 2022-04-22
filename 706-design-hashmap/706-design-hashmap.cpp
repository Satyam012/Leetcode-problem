class MyHashMap {
public:
    vector<list<pair<int,int>>>hmap;
    int mod=1003;
    MyHashMap() {
        hmap.resize(mod);
    }
    
    list<pair<int,int>>::iterator search(int key){
        int id=key%mod;
        auto it=hmap[id].begin();
        while(it!=hmap[id].end()){
            if(it->first==key)return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int id=key%mod;
        remove(key);
        hmap[id].push_back({key,value});
    }
    
    int get(int key) {
        int id=key%mod;
        auto it=search(key);
        if(it!=hmap[id].end()){
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int id=key%mod;
        auto it=search(key);
        if(it!=hmap[id].end()){
            hmap[id].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */