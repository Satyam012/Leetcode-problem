class DetectSquares {
public:
    int points[1001][1001]={};
    vector<vector<int>>pointArr;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
        pointArr.push_back(point);
    }
    
    int count(vector<int> point) {
        int ans=0,x1=point[0],y1=point[1];
        for(auto x:pointArr){
            int x3=x[0],y3=x[1];
            if(abs(x1-x3)==abs(y1-y3) && abs(x1-x3)>0){
                ans+=points[x1][y3]*points[x3][y1];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */