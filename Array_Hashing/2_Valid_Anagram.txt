/***

Given two strings s and t, return true if t is an  anagram of s, and false otherwise.
 
 https://leetcode.com/problems/valid-anagram/description/
 
 
***/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!= t.length())
            return false;
        
        int freq[26]={0};

        for(int i=0;i<s.length();i++)
        {
            freq[toupper(s[i]) - 'A']++;
        }

        for(int j=0;j<t.length();j++)
        {
            freq[toupper(t[j])- 'A']--;
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return false;
        }
        return true;
    }
};



Time complexity:  O(n)
Space complexity:  O(n)