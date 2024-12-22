/*

	https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=e9surc0r
	
	287. Find the Duplicate Number
	
	Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

	There is only one repeated number in nums, return this repeated number.

	You must solve the problem without modifying the array nums and using only constant extra space.

	 

	Example 1:

	Input: nums = [1,3,4,2,2]
	Output: 2
	
**/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]])
        {
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};

Time: O(N)
space: O(1)

