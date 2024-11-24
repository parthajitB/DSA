/**
	131. Palindrome Partitioning
	https://leetcode.com/problems/palindrome-partitioning/description/?envType=problem-list-v2&envId=ehkbkaxt
	
	Given a string s, partition s such that every substring of the partition is a palindrome
	. Return all possible palindrome partitioning of s.

	 

	Example 1:

	Input: s = "aab"
	Output: [["a","a","b"],["aa","b"]]
	Example 2:

	Input: s = "a"
	Output: [["a"]]
	
**/

class Solution {
public:

    bool isPalindrom(string s,int i, int j)
    {
        while(i<j)
        {
            if(s[i++] != s[j--])
            {
                    return false;
            }
        }
        return true;
    }
   void partitionHelper(int index,string s, vector<string> &path, vector<vector<string>> &res)
   {
        if(index==s.size())
        {
            res.push_back(path);
            return ;
        }

        for(int i=index;i<s.size();i++)
        {
            if(isPalindrom(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                partitionHelper(i+1,s,path,res);
                path.pop_back();
            }
        }
   }
    vector<vector<string>> partition(string s) {

        vector<vector<string> > v;
        vector<string> v1;
        partitionHelper(0,s,v1,v);
        return v;
    }
};


Time complexity: O(N * 2 ^ N)  where N is the length of string s. This is the worst-case time complexity when all the possible substrings are palindrome.Hence, there could be 2 
N possible substrings in the worst case. For each substring, it takes O(N) time to generate the substring and determine if it is a palindrome or not. 

space complexity :  O(N)   where N is the length of the string s. This space will be used to store the recursion stack. For s = aaa, the maximum depth of the recursive call stack is 3 which is equivalent to N.

