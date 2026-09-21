class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word , int r , int c, int idx , vector<vector<int>>&vis) {
        int rows = board.size();
        int cols = board[0].size();
        vector<int> dr = {-1 , 0, 0 ,1};
        vector<int> dc = {0 , 1, -1, 0};

        if(idx == word.length()-1) return true;

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if( nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                        vis[nr][nc] != 1 && board[nr][nc] == word[idx+1]){

                            vis[nr][nc] = 1;

                            if(dfs(board , word , nr , nc , idx+1,vis) ){
                                return true;
                            }

                 vis[nr][nc] = 0;
                 }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
    
        vector<vector<int>> vis(rows , vector<int> (cols , 0) );
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(dfs(board,word,i,j,0,vis)) return true;

                    vis[i][j] = 0;
                }
            }
        }

        return false;
        
    }
};