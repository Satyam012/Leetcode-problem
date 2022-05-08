class LRUCache {
public:
list<int>cache;
    int size;
    unordered_map<int,list<int>::iterator>keyAddress;   //{key,list_address}
    unordered_map<int,int>keyVal;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    void update(int key,int value){
        auto it=keyAddress[key];
        cache.erase(it);
        cache.push_front(key);
        keyAddress[key]=cache.begin();
        keyVal[key]=value;
    }
    
    int get(int key) {
        if(keyVal.find(key)==keyVal.end())return -1;
        update(key,keyVal[key]);
        return keyVal[key];
    }
    
    void put(int key, int value) {
        int val=get(key);
        if(val==-1){
            cache.push_front(key);
            keyVal[key]=value;
            keyAddress[key]=cache.begin();
            
            if(cache.size()>size){
                keyAddress.erase(cache.back());
                keyVal.erase(cache.back());
                cache.pop_back();
            }
        } else{
            update(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */