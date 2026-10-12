// Leetcode 130. Surrounded Regions


// My Approach

bool helper(vector<vector<char>>& board, int i, int j, int n, int m, vector<vector<bool>>& vis, vector<pair<int,int>>& temp){

    if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O' || vis[i][j]) return true;

    if(i==0 || j==0 || i==n-1 || j==m-1) return false;

    vis[i][j] = true;

    temp.push_back({i,j});

    bool top = helper(board, i+1, j, n, m, vis, temp);
    bool bot = helper(board, i-1, j, n, m, vis, temp);
    bool ryt = helper(board, i, j+1, n, m, vis, temp); 
    bool lef = helper(board, i, j-1, n, m, vis, temp);

    if(top && lef && ryt && bot) return true;

    return false;

}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O' && !vis[i][j]) {
                vector<pair<int,int>> temp;
                if(helper(board, i, j, n, m, vis, temp)){
                    for(auto p: temp){
                        board[p.first][p.second] = 'X';
                    }
                }
                
            }
        }
    }
}
// Time Complexity: O(n*m) + O(n*m) for the DFS traversal and flipping the cells
// where n is the number of rows and m is the number of columns in the board. Each cell is visited at most once. 
// Space Complexity: O(n*m) for the visited matrix and the recursion stack in the worst

void dfs(vector<vector<char>>& board, int i, int j, int n, int m, vector<vector<bool>>& vis){
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O' || vis[i][j]) return;

    vis[i][j] = true;
    board[i][j] = 'B'; // Mark the cell as visited and part of the border-connected region

    dfs(board, i+1, j, n, m, vis);
    dfs(board, i-1, j, n, m, vis);
    dfs(board, i, j+1, n, m, vis); 
    dfs(board, i, j-1, n, m, vis);
}

void solveDFS(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    // Step 1: Mark all 'O's connected to the border as visited

    // Check first and last columns
    for(int i=0; i<n; i++){
        dfs(board, i, 0, n, m, vis);
        dfs(board, i, m-1, n, m, vis);
    }


    // Check first and last rows
    for(int j=0; j<m; j++){
        dfs(board, 0, j, n, m, vis);
        dfs(board, n-1, j, n, m, vis);
    }

    // Now all 'O's connected to the border are marked as 'B'. 
    // All remaining 'O's are surrounded and should be flipped to 'X'.
    // And all 'B's should be flipped back to 'O' as they are connected to the border.

    // Step 2: Flip all remaining 'O's to 'X' and 'B's back to 'O'
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O') {
                board[i][j] = 'X'; // Flip surrounded 'O' to 'X'
            } else if(board[i][j] == 'B') {
                board[i][j] = 'O'; // Flip back border-connected 'B' to 'O'
            }
        }
    }

}

// Time Complexity: O(n*m) for the DFS traversal and flipping the cells
// Space Complexity: O(n*m) for the visited matrix and the recursion stack in the worst

