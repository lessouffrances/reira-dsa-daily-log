class Solution 
{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        ROW = obstacleGrid.size();
        COL = obstacleGrid[0].size();
        if (obstacleGrid[ROW-1][COL-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        memo.resize(ROW, vector<int>(COL, -1));

        return dfs(0, 0, obstacleGrid);
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {1,0} };
    vector<vector<int>> memo;
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid)
    {
        if (row == ROW-1 && col == COL-1) {
            return 1;
        }
        if (memo[row][col] != -1) return memo[row][col];
        int numWays = 0;
        for (auto& DIR : DIRS) {
            int newR = row + DIR.first;
            int newC = col + DIR.second;
            if (newR >= ROW || newC >= COL || obstacleGrid[newR][newC] == 1) continue;
            numWays += dfs(newR, newC, obstacleGrid);
        }
        memo[row][col] = numWays;
        return numWays;
    }
};