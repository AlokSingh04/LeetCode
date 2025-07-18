class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int r, int c, int& size){
        if(i==r || j==c || i<0 || j<0 || grid[i][j] == 0){
            return;
        }

        size++;
        grid[i][j] = 0;

        DFS(grid,i,j+1,r,c,size);
        DFS(grid,i-1,j,r,c,size);
        DFS(grid,i,j-1,r,c,size);
        DFS(grid,i+1,j,r,c,size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    int size=0;
                    DFS(grid,i,j,r,c,size);
                    res = max(res,size);
                }
            }
        }

        return res;
    }
};