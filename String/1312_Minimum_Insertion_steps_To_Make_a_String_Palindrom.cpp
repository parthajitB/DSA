/*
		https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/?envType=problem-list-v2&envId=ehkbkaxt
		
		
		1312. Minimum Insertion Steps to Make a String Palindrome

		Given a string s. In one step you can insert any character at any index of the string.

		Return the minimum number of steps to make s palindrome.

		A Palindrome String is one that reads the same backward as well as forward.

		 

		Example 1:

		Input: s = "zzazz"
		Output: 0
		Explanation: The string "zzazz" is already palindrome we do not need any insertions.
		Example 2:

		Input: s = "mbadm"
		Output: 2
		Explanation: String can be "mbdadbm" or "mdbabdm".
		Example 3:

		Input: s = "leetcode"
		Output: 5
		Explanation: Inserting 5 characters the string becomes "leetcodocteel".
		
*/


class Solution {
public:
    int lcs(string s,string sReverse,int m, int n,vector<vector<int>> &dp)
    {
        if( m==0 || n==0)
            return 0;

        if(dp[m][n] != -1)
            return dp[m][n];

        if(s[m-1]== sReverse[n-1])
        {
            return 1+lcs(s,sReverse,m-1,n-1,dp);
        }
        return  0+ max(lcs(s,sReverse,m-1,n,dp),lcs(s,sReverse,m,n-1,dp));
        
    }
    int minInsertions(string s) {
        int n=s.length();
        string sReverse=s;
        reverse(sReverse.begin(),sReverse.end());

         vector<vector<int>> dp(n+1,vector<int>(n+1));

         for(int i=0;i<=n;i++)
         {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
         }

    return n- lcs(s,sReverse,n,n,dp);
    }
};

Time complexity: O(n2)

	Initializing the memo array takes O(n2) time.Since there are O(n2) states that we need to iterate over, the recursive function is called O(n2) times.
	
Space complexity: O(n2)

/************* Iterative **********/

class Solution {
public:
    int lcs(string &s,string &sReverse, int m, int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if( i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(s[i-1] == sReverse[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        int n=s.length();
        string sReverse=s;
        reverse(sReverse.begin(),sReverse.end());

        return n- lcs(s,sReverse,n,n);
    }
};


Time complexity: O(n2)
	
Space complexity: O(n2)