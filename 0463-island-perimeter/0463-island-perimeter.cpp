class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int r, int c, int& parameter){

        if(i==r || j==c || i<0 || j<0 || grid[i][j]==0){
            parameter++;
            return;
        }

        if(grid[i][j]==-1) return;

        grid[i][j] = -1;

        DFS(grid,i,j+1,r,c,parameter);
        DFS(grid,i-1,j,r,c,parameter);
        DFS(grid,i,j-1,r,c,parameter);
        DFS(grid,i+1,j,r,c,parameter);        
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int parameter = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    DFS(grid,i,j,r,c,parameter);
                    return parameter;
                }
            }
        }

        return parameter;
    }
};