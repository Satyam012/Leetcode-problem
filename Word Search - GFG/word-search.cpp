// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool check(vector<vector<char>>&board, int id,int x,int y,string &word){
        if(id==word.length())return 1;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size())return false;
        if(board[x][y]!=word[id])return false;
        
        for(int i=0;i<4;i++){
            char c=board[x][y];
            board[x][y]='#';
            if(check(board,id+1,x+dir[i][0],y+dir[i][1],word)==1)return true;
            board[x][y]=c;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(check(board,0,i,j,word)==1)return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends