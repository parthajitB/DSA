/**
	https://leetcode.com/problems/custom-sort-string/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	791. Custom Sort String
	
	You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

	Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

	Return any permutation of s that satisfies this property.

	 

	Example 1:

	Input: order = "cba", s = "abcd"

	Output: "cbad"

	Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

	Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
	
**/

class Solution {
public:
    string customSortString(string order, string s) {

       unordered_map<char,int> m; 
       string returnString="";

       for( char c: s)
       {
            m[c]++;
       }
       
       for(char c: order)
       {
            while(m[c]-- >0)
            {
                returnString=returnString+c;
            }
       }

       for(auto it: m)
       {
            while(it.second-->0)
            {
                returnString =returnString + it.first;
            }
       }
        return returnString;
    }
};


Time :  O(n)
space: O(n)

