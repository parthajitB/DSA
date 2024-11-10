/**
	Given an array of strings strs, group the anagrams together. You can return the answer in any order.
	
	Example 1:

	Input: strs = ["eat","tea","tan","ate","nat","bat"]

	Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

	Explanation:

	There is no string in strs that can be rearranged to form "bat".
	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
	
	
https://leetcode.com/problems/group-anagrams/description/

**/

class Solution {
public:
    string getKey(string str)
    {
        vector<int> count(26);

        for(int i=0;i<str.length();i++)
        {
            count[str[i]-'a']++;
        }

        string key="";

        for(int i=0;i<count.size();i++)
        {
            key.append(to_string(count[i]) + '#');
        }

        //cout<<"key is ::"<<key<<endl;
       return key ;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(int i=0;i<strs.size();i++)
        {
            string key=getKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto it=m.begin();it!= m.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};


Time complexity:   O(N*M)
Space complexity:  O(N*M)