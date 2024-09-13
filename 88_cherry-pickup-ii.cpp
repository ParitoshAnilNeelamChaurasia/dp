// https://leetcode.com/problems/cherry-pickup-ii/

class Solution
{
public:
    int m, n;
    int dp[101][101][101];
    bool is_valid(int i, int j)
    {
        if (i < m && j >= 0 && j < n)
            return true;

        return false;
    }
    int f(int row, int robo_1_y, int robo_2_y, vector<vector<int>> &grid)
    {
        if (row >= m)
        {
            return 0;
        }

        if (dp[row][robo_1_y][robo_2_y] != -1)
        {
            return dp[row][robo_1_y][robo_2_y];
        }

        int count = grid[row][robo_1_y];

        // same cell can be taken once
        if (robo_1_y != robo_2_y)
        {
            count += grid[row][robo_2_y];
        }

        int ans = 0;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                int x = row + 1;
                int new_col_robo_1 = i + robo_1_y;
                int new_col_robo_2 = j + robo_2_y;

                if (is_valid(x, new_col_robo_1) == true && is_valid(x, new_col_robo_2) == true)
                {
                    ans = max(ans, f(x, new_col_robo_1, new_col_robo_2, grid));
                }
            }
        }
        return dp[row][robo_1_y][robo_2_y] = count + ans;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));
        return f(0, 0, n - 1, grid);
    }
};
