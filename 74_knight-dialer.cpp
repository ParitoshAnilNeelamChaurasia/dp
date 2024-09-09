// https://leetcode.com/problems/knight-dialer/description/

class Solution
{
public:
    const int mode = 1e9 + 7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}};

    int dp[5001][11];
    int f(int n, int cell)
    {
        if (n == 0)
        {
            return 1; // got one cell
        }

        if (dp[n][cell] != -1)
        {
            return dp[n][cell];
        }

        int ans = 0;

        for (int &next_cell : adj[cell])
        {
            ans = (ans + f(n - 1, next_cell)) % mode;
        }
        return dp[n][cell] = ans;
    }
    int knightDialer(int n)
    {
        int res = 0;

        memset(dp, -1, sizeof(dp));

        for (int cell = 0; cell <= 9; ++cell)
        {
            res = (res + f(n - 1, cell)) % mode;
        }
        return res;
    }
};
