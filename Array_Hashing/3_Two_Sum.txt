/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

https://leetcode.com/problems/two-sum/description/


**/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int key=target-nums[i];
            if(m.find(key)!=m.end())
            {
                result.push_back(m.find(key)->second);
                result.push_back(i);
            }
            m.insert(pair<int,int>(nums[i],i));
        }
        return result;
    }
};



Time complexity:  O(n)
Space Complexity:  O(n)