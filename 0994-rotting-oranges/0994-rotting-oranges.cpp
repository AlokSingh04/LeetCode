class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int fresh = 0, rotten = 0;

        queue<pair<int,int>> que;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2){
                    rotten++;
                    que.push({i,j});
                }
            }
        }

        if(fresh == 0) return 0;

        int ans = -1;
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        while(!que.empty()){
            int size = que.size();
            ans++;

            for(int i=0;i<size;i++){
                pair<int,int> node = que.front();
                que.pop();
                for(int j=0;j<4;j++){
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];

                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y] == 1){
                        que.push({x,y});
                        fresh--;
                        grid[x][y] = 2;
                    }
                }
            }
        }

        return fresh==0 ? ans : -1;
    }
};