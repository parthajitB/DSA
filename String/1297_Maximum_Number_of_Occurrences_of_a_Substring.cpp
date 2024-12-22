/**
	1297. Maximum Number of Occurrences of a Substring
	
	https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	
	Given a string s, return the maximum number of occurrences of any substring under the following rules:

	The number of unique characters in the substring must be less than or equal to maxLetters.
	The substring size must be between minSize and maxSize inclusive.
	 

	Example 1:

	Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
	Output: 2
	Explanation: Substring "aab" has 2 occurrences in the original string.
	It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
	Example 2:

	Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
	Output: 2
	Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
	
**/

class Solution {
public:

    int uniqsubStr(string &str)
    {
        set<char> s;

        for(char c: str)
        {
            s.insert(c);
        }
        return s.size();
    }

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int stringSize=s.length();

        if(stringSize < minSize)
            return 0;

        int count=0;

        unordered_map<string,int> m;

        for(int i=0;i+minSize <= stringSize ;i++)
        {
            string sub=s.substr(i,minSize);

            if(uniqsubStr(sub) <= maxLetters)
            {
                m[sub]++;
            }

            count=max(count,m[sub]);

        }
        return count;
    }
};


time complexity:  O( N)
space complexity:  O( N)