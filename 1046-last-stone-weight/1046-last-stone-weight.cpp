class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>q;
        for(int i=0;i<s.size();i++)
        {
            q.push(s[i]);
        }
        while(q.size()>1)
        {
            int x;
            x=q.top();
            q.pop();
            if(x==q.top())q.pop();
            else{
                x=x-q.top();
                q.pop();
                q.push(x);
            }
        }
        if(q.size()==0)return 0;
        else return q.top();
    }
};