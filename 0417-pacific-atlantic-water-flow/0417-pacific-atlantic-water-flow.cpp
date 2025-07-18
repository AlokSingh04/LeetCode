class Solution {
public:
    void DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int r, int c, int prev){
        if(i==r || j==c || i<0 || j<0 || visited[i][j] || grid[i][j] < prev){
            return;
        }

        visited[i][j] = 1;
        
        DFS(grid,visited,i,j+1,r,c,grid[i][j]);
        DFS(grid,visited,i-1,j,r,c,grid[i][j]);
        DFS(grid,visited,i,j-1,r,c,grid[i][j]);
        DFS(grid,visited,i+1,j,r,c,grid[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pasafic(r,vector<bool>(c,0));
        vector<vector<bool>> atlantic(r,vector<bool>(c,0));
        for(int i=0;i<r;i++){
            DFS(heights,pasafic,i,0,r,c,heights[i][0]);
            DFS(heights,atlantic,i,c-1,r,c,heights[i][c-1]);
        }
        for(int j=0;j<c;j++){
            DFS(heights,pasafic,0,j,r,c,heights[0][j]);
            DFS(heights,atlantic,r-1,j,r,c,heights[r-1][j]);
        }

        vector<vector<int>> res;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pasafic[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};