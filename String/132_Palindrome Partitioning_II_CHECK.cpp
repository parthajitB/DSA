/**
	132 Palindrome Partitioning II
	
	Given a string s, partition s such that every 
	substring of the partition is a  palindrome
	.

	Return the minimum cuts needed for a palindrome partitioning of s.

	 

	Example 1:

	Input: s = "aab"
	Output: 1
	Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
	
**/

class Solution {
public:

    bool isPalindrom(int i,int j, string s)
    {
        while(i<j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int partition(int start,int end,string s,vector<int> &dp)
    {
        if( start==end  ) return 0;

        if( dp[start]!=-1)
            return dp[start];

        int mincost=INT_MAX;

        for(int j=start;j<end;j++)
        {
            if(isPalindrom(start,j,s))
            {
                    int cost=1+ partition(j+1,end,s,dp);
                    mincost=min(mincost,cost);
            }
        }
        return dp[start]=mincost;

    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
        return partition(0,n,s,dp) - 1;
    }
};

 Time Complexity: O(N2)
Reason: There are a total of N states and inside each state, a loop of size N(apparently) is running.

space complexity:  O(n)

#############Time OUT in Leetcode#############