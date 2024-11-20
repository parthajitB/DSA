/**
	https://leetcode.com/problems/valid-palindrome/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

	Given a string s, return true if it is a palindrome, or false otherwise.

	 

	Example 1:

	Input: s = "A man, a plan, a canal: Panama"
	Output: true
	Explanation: "amanaplanacanalpanama" is a palindrome.
	
	
*/


class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0;
        int j=s.length()-1;

        while(i<j)
        {
            if(!isalnum(s[i]))
            {
                i++;
            }
            else if(!isalnum(s[j]))
            {
                j--;
            }
            else if( tolower(s[i])== tolower(s[j]) )
            {
                i++;
                j--;
            }
            else
                return false;

        }
        return true;
    }
};


Time Complexity: O(n)
Space Complexity :  O(1)

