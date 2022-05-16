class StockPrice {
public:
    priority_queue<pair<int,int>>pq;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pqm;
    unordered_map<int,int>mp;
    int cur=0;
    
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        mp[timestamp]=price;
        pq.push({price,timestamp});
        pqm.push({price,timestamp});
        cur=max(cur,timestamp);
    }
    
    int current() {
        return mp[cur];
    }
    
    int maximum() {
        //return 0;
        // 10-1
        // 8-1
        // 7-1
        auto p=pq.top();
        while(p.first!=mp[p.second]){
            pq.pop();
            p=pq.top();
        }
        return p.first;
    }
    
    int minimum() {
        //return 0;
        auto p=pqm.top();
        while(p.first!=mp[p.second]){
            pqm.pop();
            p=pqm.top();
        }
        return p.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */