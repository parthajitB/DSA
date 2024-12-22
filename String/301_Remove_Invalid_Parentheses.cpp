/**
		https://leetcode.com/problems/remove-invalid-parentheses/description/?envType=problem-list-v2&envId=ehkbkaxt
		
		301. Remove Invalid Parentheses
		
		Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

	Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

	 

	Example 1:

	Input: s = "()())()"
	Output: ["(())()","()()()"]
	Example 2:

	Input: s = "(a)())()"
	Output: ["(a())()","(a)()()"]
	Example 3:

	Input: s = ")("
	Output: [""]
	
**/

class Solution {
public:

    int findInvalidCount(string s)
    {
        stack<int> sStack;

        for( auto it: s)
        {
            if( it== '(')
            {
                sStack.push(it);
            }
            else if( it == ')')
            {
                if( !sStack.empty() &&  sStack.top()=='(')
                {
                    sStack.pop();
                }
                else
                {
                     sStack.push(it);
                }
            }
        }
        return sStack.size();
    }

    void helper(string s,vector<string> &ans,map<string,bool> &m,int removeCount)
    {
            if( m[s])
            {
                return;
            }
            else
            {
                m[s]=true;
            }

            if(removeCount==0)
            {
                int count=0;
                count=findInvalidCount(s);
                if(count==0)
                {
                    ans.push_back(s);
                }
                return;
            }

            for(int i=0;i<s.length();i++)
            {
                string left=s.substr(0,i);
                string right =s.substr(i+1);
                helper(left+right,ans,m,removeCount-1);

            }
    }
    vector<string> removeInvalidParentheses(string s) {
         int removeCount=findInvalidCount(s);
         vector<string> ans;
         map<string,bool> m;
         helper(s, ans, m , removeCount);
         return ans;
    }
};

Time:  O(2^N)

space: O(N)
