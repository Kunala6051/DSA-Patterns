#include <bits/stdc++.h>
using namespace std;

// LeetCode 733 - Flood Fill

// MY initial BFS Approach

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    q.push({sr,sc});

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        if(i-1>=0 && !vis[i-1][j] && image[i-1][j]==image[i][j]){
            vis[i-1][j] = true;
            q.push({i-1,j});
        }
        if(j-1>=0 && !vis[i][j-1] && image[i][j-1]==image[i][j]){
            vis[i][j-1] = true;
            q.push({i,j-1});
        }
        if(i+1<n && !vis[i+1][j] && image[i+1][j]==image[i][j]){
            vis[i+1][j] = true;
            q.push({i+1,j});
        }
        if(j+1<m && !vis[i][j+1] && image[i][j+1]==image[i][j]){
            vis[i][j+1] = true;
            q.push({i,j+1});
        }
        image[i][j]=color;
        q.pop();
    }
    return image;

}

// Optimal DFS Approach

void dfs(vector<vector<int>>& image, int i, int j, int newcolor, int ogcolor){
    if(i<0 || j<0 || j>=image[0].size() || i>=image.size() || image[i][j]!=ogcolor || image[i][j]==newcolor) return;
    
    image[i][j] = newcolor; 
    dfs(image, i+1, j, newcolor, ogcolor);
    dfs(image, i-1, j, newcolor, ogcolor);
    dfs(image, i, j-1, newcolor, ogcolor);
    dfs(image, i, j+1, newcolor, ogcolor);
}

vector<vector<int>> floodFillDFS(vector<vector<int>>& image, int sr, int sc, int color) {
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}

int main(){
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = floodFillDFS(image, sr, sc, color);
    for(auto row: result){
        for(int val: row){
            cout << val << " ";
        }
        cout << endl;
    }
}