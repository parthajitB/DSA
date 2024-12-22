/**
	https://leetcode.com/problems/number-of-matching-subsequences/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	792. Number of Matching Subsequences
	
	Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 
 
 */
 
 class Solution {
public:
    bool isSubSequence(string &s,string &x, int m, int n)
    {
        int j=0;
        for(int i=0; i<m && j<n; i++)
        {
            if(s[i]==x[j])
            {
                j++;
            }
        }

        return j==n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string,bool> m;
        int count=0;

        for( auto x: words)
        {
            if(m.find(x) != m.end())
            {
                if( m[x] == true)
                {
                   count++;
                }
                continue;
            }

            m[x]=isSubSequence(s,x,s.size(),x.size());
            count=count+ (m[x]==true);
        }

        return count;
    }
};

Time : O(N+M)

Space:  O(N)


