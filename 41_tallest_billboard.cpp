// https://leetcode.com/problems/tallest-billboard/

// recursive approach
class Solution {
public:
    int n ;

    int f(int i , vector<int> &rods , int l1 , int l2)
    {
        if(i >= n)
        {
            if(l1 == l2)
            return l1 ;

            return 0 ;
        }

        int take_l1 = f(i+1 , rods , l1 + rods[i] , l2)  ;

        int take_l2 = f(i+1 , rods , l1 , l2 + rods[i] )  ;

        int dont = f(i+1 , rods , l1 , l2) ;

        return max({take_l1 , take_l2 , dont}) ;

    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size() ;

        return f(0 , rods , 0 , 0) ;
    }
};

// memoization
class Solution {
public:
    int n ;

    int dp[21][10003] ;

    int f(int i , vector<int> &rods , int diff)
    {
        if(i >= n)
        {
            if(diff == 0)
            return 0;

            return INT_MIN ;
        }

        if(dp[i][diff + 5000] != -1)
        return dp[i][diff+5000] ;

        int take_l1 = rods[i] + f(i+1 , rods , diff - rods[i])  ;

        int take_l2 = rods[i] + f(i+1 , rods , diff + rods[i] )  ;

        int dont = f(i+1 , rods , diff) ;

        return dp[i][diff+5000] = max({take_l1 , take_l2 , dont}) ;

    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size() ;

        memset(dp,-1,sizeof(dp)) ;

        return f(0 , rods , 0 )/2 ;
    }
};
