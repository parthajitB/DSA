/***
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

https://leetcode.com/problems/contains-duplicate/description/


**/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator itr;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->second > 1)
            {
                return true;
            }
        }
       return false;
    }
};

Time complexity:  O(n)
Space complexity:  O(n)