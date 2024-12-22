/**
		1790. Check if One String Swap Can Make Strings Equal
		
		https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=problem-list-v2&envId=ehkbkaxt
		
		You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

	Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

	 

	Example 1:

	Input: s1 = "bank", s2 = "kanb"
	Output: true
	Explanation: For example, swap the first character with the last character of s2 to make "bank".
	Example 2:

	Input: s1 = "attack", s2 = "defend"
	Output: false
	Explanation: It is impossible to make them equal with one string swap.
	Example 3:

	Input: s1 = "kelb", s2 = "kelb"
	Output: true
	Explanation: The two strings are already equal, so no string swap operation is required.
	 
		
**/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
            return true;
        vector<int> vec;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                vec.push_back(s1[i]);
                vec.push_back(s2[i]);
            }
        }
        cout<<"vec size is :"<<vec.size()<<endl;
        if(vec.size()>4 || vec.size()<4)
            return false;
        else 
        {
            if(vec[0]==vec[3] && vec[1]==vec[2])
                return true;
        }
        return false;
    }
};

Time:  O(n)
space: O(n)

