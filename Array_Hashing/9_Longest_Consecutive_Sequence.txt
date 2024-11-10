/**

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
 
 https://leetcode.com/problems/longest-consecutive-sequence/description/
**/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> v;
        int length=0;
        for(int i=0;i<nums.size();i++)
        {
            int key=nums[i];
            v.clear();
            while(std::find(nums.begin(),nums.end(),key)!=nums.end())
            {
                v.push_back(key);
                key=key+1;
                //v.push_back(key);
            }

            if(v.size()> length)
            {
                length=v.size();
            }
        }
        return length;
    }
};


time complexity:  O(n2)
space complexity:  O(1)



Time limit exceeded

