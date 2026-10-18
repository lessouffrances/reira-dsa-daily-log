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
    vector<pair<int, int>> DIRS = { {1,0}, {0,1} };
    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        if (row == ROW-1 && col == COL-1) return grid[row][col];
        if (memo[row][col] != -1) return memo[row][col];

        int mininumPathSum = INT_MAX;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;

            if (newR>=ROW || newC>=COL) continue;
            mininumPathSum = min(mininumPathSum, grid[row][col]+dfs(newR, newC, grid));
        }
        memo[row][col] = mininumPathSum;
        return mininumPathSum;
    }
};