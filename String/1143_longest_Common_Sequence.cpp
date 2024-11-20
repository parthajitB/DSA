/**
	Longest Common Subsequence
	
	Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

	A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

	For example, "ace" is a subsequence of "abcde".
	A common subsequence of two strings is a subsequence that is common to both strings.

	 

	Example 1:

	Input: text1 = "abcde", text2 = "ace" 
	Output: 3  
	Explanation: The longest common subsequence is "ace" and its length is 3.
	
**/

class Solution {
public:
        int lcsUtil(int len1,int len2,string &s1,string &s2,vector<vector<int>> &dp)
        {
            if( len1<0 || len2<0)
                return 0;

            if(dp[len1][len2] != -1)
            {
                    return dp[len1][len2];
            }

            if( s1[len1] == s2[len2])
            {
                    return dp[len1][len2]=1+ lcsUtil(len1-1,len2-1,s1,s2,dp);
            }
            else
            {
                return dp[len1][len2]=0+ max(lcsUtil(len1-1,len2,s1,s2,dp),lcsUtil(len1,len2-1,s1,s2,dp));
            }
        }
        
        int longestCommonSubsequence(string text1, string text2) 
        {
        
            int len1=text1.size();
            int len2=text2.size();

            vector<vector<int>> dp(len1,vector<int>(len2,-1));

            return lcsUtil(len1-1,len2-1,text1,text2,dp);
        }
};

Time Complexity: O(N*M)

		Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.

Space Complexity: O(N*M) + O(N+M)

		Reason: We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).