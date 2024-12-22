/**
	https://leetcode.com/problems/increasing-decreasing-string/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	1370. Increasing Decreasing String
		
		You are given a string s. Reorder the string using the following algorithm:

		Remove the smallest character from s and append it to the result.
		Remove the smallest character from s that is greater than the last appended character, and append it to the result.
		Repeat step 2 until no more characters can be removed.
		Remove the largest character from s and append it to the result.
		Remove the largest character from s that is smaller than the last appended character, and append it to the result.
		Repeat step 5 until no more characters can be removed.
		Repeat steps 1 through 6 until all characters from s have been removed.
		If the smallest or largest character appears more than once, you may choose any occurrence to append to the result.

		Return the resulting string after reordering s using this algorithm.

		 

		Example 1:

		Input: s = "aaaabbbbcccc"
		Output: "abccbaabccba"
		Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
		After steps 4, 5 and 6 of the first iteration, result = "abccba"
		First iteration is done. Now s = "aabbcc" and we go back to step 1
		After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
		After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
		
		
**/

class Solution {
public:
    string sortString(string s) {
        
        unordered_map<char, int> mp;
        string returnString="";

        for(char c: s)
        {
            mp[c]++;
        }

        bool found=true;

        while(found)
        {
            found =false;

            for(char c='a' ; c<='z';c++)
            {
                if(mp[c])
                {
                    returnString.push_back(c);
                    mp[c]--;
                    found=true;
                }
            }

            for( char c='z'; c>='a';c--)
            {
                if(mp[c])
                {
                    returnString.push_back(c);
                    mp[c]--;
                    found=true;
                }
            }
        }
        return returnString;
    }
};

time complexity: O(N)
space complecity: O(N)