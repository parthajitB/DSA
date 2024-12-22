/**
		1055. Shortest Way to Form String
		
		https://leetcode.com/problems/shortest-way-to-form-string/description/


A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".






	https://leetcode.com/problems/shortest-way-to-form-string/editorial/



**/



class Solution {
public:
    int shortestWay(string source, string target) {
        bool sourceArray[26]={false};

        for(char c: source)
        {
            sourceArray[c - 'a']= true;
        }

        for( char c: target)
        {
            if(!sourceArray[c-'a'])
            {
                return -1;
            }
        }

        int sourceIterator=0;
        int sourceLength=source.length();

        int actualCount=0;

        for(char c: target)
        {
            if(sourceIterator==0)
            {
                actualCount++;
            }
            while( source[sourceIterator] !=c)
            {
                sourceIterator= (sourceIterator+1) %sourceLength;

                if(sourceIterator==0)
                {
                    actualCount++;
                }
            }
            sourceIterator= (sourceIterator+1) %sourceLength;
        }

        return actualCount;

    }
};


Time complexity: O(S* T), where T is length of target and S is length of source.

		O(S) to create a boolean array to mark all characters of source.

		O(T) to check if all characters of target are present in source.

		

		Thus, the total time complexity is O(S + T).

Space complexity: O(1).

	the boolean array to mark all characters of source takes O(1) space.