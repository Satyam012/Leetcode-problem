class Solution {
public:
    int findComplement(int num) {
        int x=log2(num)+1;
        x=pow(2,x)-1;
        x=(x^num);
        return x;
    }
};