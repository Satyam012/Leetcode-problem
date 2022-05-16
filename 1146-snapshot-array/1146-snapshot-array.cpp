class SnapshotArray {
public:
    map<int, map<int, int>> a;
    int cur_snap = 0;
    
    SnapshotArray(int length) {}
    
    int snap() { 
        return cur_snap++; 
    }
    
    void set(int index, int val) { 
      a[index][cur_snap] = val; 
    }
    
    int get(int index, int snap_id) {
      auto it = a[index].upper_bound(snap_id);
      if(it==a[index].begin())return 0;
      else{
          it--;
          return it->second;
      }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */