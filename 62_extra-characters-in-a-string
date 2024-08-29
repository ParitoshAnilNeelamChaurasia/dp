// https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02

class Solution {
public:
    int n ;

    set<string> st ;

    int dp[51] ;

    int f(int ind , string &s)
    {
        if(ind >= n)
        {
            return 0 ;
        }

        if(dp[ind] != -1)
        {
           return dp[ind] ; 
        }

        string curr_str = "" ;
        int min_extra = n ;

        for(int i = ind ; i < n ; ++i)
        {
            curr_str.push_back(s[i]) ;

            int curr_extra ;

            if(st.find(curr_str) == st.end())
            {
                curr_extra = curr_str.size() ;
            }
            else
            {
                curr_extra = 0 ;
            }

            int next_extra = f(i + 1 , s) ;

            int tot_extra = curr_extra + next_extra ;

            min_extra = min(min_extra , tot_extra) ;
        }
        return dp[ind] = min_extra ;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size() ;

        memset(dp,-1,sizeof(dp)) ;
        for(string &it : dictionary)
        {
            st.insert(it) ;
        }
        
        return f(0 , s) ;
    }
};
