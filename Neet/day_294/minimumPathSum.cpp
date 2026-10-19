class Solution 
{
    public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        ROW = grid.size();
        COL = grid[0].size();
        memo.resize(ROW, vector<int>(COL, -1));

        return dfs(0, 0, grid);
    }

    private:
    int ROW, COL;
    vector<vector<int>> memo;
    vector<pair<int, int>> DIRS = { {0,1}, {1,0} };
    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        if (row == ROW-1 && col == COL-1) return grid[ROW-1][COL-1];
        if (memo[row][col] != -1) return memo[row][col];
        int res = INT_MAX;

        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            if (newR>=ROW || newC>=COL) continue;
            res = min(res, grid[row][col]+dfs(newR, newC, grid));
        }

        memo[row][col] = res;
        return res;
    }
};