/**
	https://leetcode.com/problems/valid-palindrome-ii/description/?envType=problem-list-v2&envId=e9snhf4h
	
	680. Valid Palindrome II

	Companies
	Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

	Example 1:

	Input: s = "aba"
	Output: true
	Example 2:

	Input: s = "abca"
	Output: true
	Explanation: You could delete the character 'c'.
	Example 3:

	Input: s = "abc"
	Output: false
	
*/

class Solution {
public:

    bool checkPalindrome(string s, int begin, int end)
    {
        while(begin<end)
        {
            if(s.at(begin) != s.at(end))
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return (checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1));
            }

            i++;
            j--;
        }

        return true;
    }
};

Time:  O(N+M)->  O(N)
space:  O(N)

