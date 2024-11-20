/**
	Palindromic Substrings
	
	Given a string s, return the number of palindromic substrings in it.

	A string is a palindrome when it reads the same backward as forward.

	A substring is a contiguous sequence of characters within the string.

	 

	Example 1:

	Input: s = "abc"
	Output: 3
	Explanation: Three palindromic strings: "a", "b", "c".
	
**/

class Solution {
public:
    void middleOut(string s, int i, int j, int& result) 
    {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
     }

    int countSubstrings(string s) 
    {
          int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // odd-length palindromes, single character center
            middleOut(s, i, i, result);
            // even-length palindromes, consecutive characters center
            middleOut(s, i, i + 1, result);
        }
        
        return result;
    }
};

Time compelxity: O(N2)
Space complexity:  O(1)


