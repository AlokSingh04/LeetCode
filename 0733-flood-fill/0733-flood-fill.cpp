class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i,int j,int& r,int& c,int old_color, int& new_color){
        if(i==r || j==c || i<0 || j<0 || grid[i][j]!=old_color || grid[i][j]==new_color){
            return;
        }

        grid[i][j] = new_color;

        DFS(grid,i,j+1,r,c,old_color,new_color);
        DFS(grid,i-1,j,r,c,old_color,new_color);
        DFS(grid,i,j-1,r,c,old_color,new_color);
        DFS(grid,i+1,j,r,c,old_color,new_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        int r = image.size();
        int c = image[0].size();

        DFS(image,sr,sc,r,c,image[sr][sc],new_color);

        return image;
    }
};