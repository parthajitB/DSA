/**
	409. Longest Palindrome
	
	https://leetcode.com/problems/longest-palindrome/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	
	Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
	palindrome
	 that can be built with those letters.

	Letters are case sensitive, for example, "Aa" is not considered a palindrome.

	 

	Example 1:

	Input: s = "abccccdd"
	Output: 7
	Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
	Example 2:

	Input: s = "a"
	Output: 1
	Explanation: The longest palindrome that can be built is "a", whose length is 1.
	
**/

class Solution {
public:
    int longestPalindrome(string s) {
        
        int oddFreqCount=0;

        unordered_map<char,int> m;

        for(auto c:s)
        {
            m[c]++;

            if(m[c] %2 ==1)
            {
                oddFreqCount++;
            }
            else
            {
                oddFreqCount--;
            }
        }

        if( oddFreqCount > 0)
            return s.length()-oddFreqCount +1;
        else
            return s.length();
    }
};

Time:  O(n)
spac: O(n)-> O(1) n here is 52  unique char hence its O(1)