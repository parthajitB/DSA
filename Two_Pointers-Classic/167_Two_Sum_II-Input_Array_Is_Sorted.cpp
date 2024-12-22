/**
	https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=e9snhf4h
	
	167. Two Sum II - Input Array Is Sorted
	
	Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

	Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

	The tests are generated such that there is exactly one solution. You may not use the same element twice.

	Your solution must use only constant extra space.

	 

	Example 1:

	Input: numbers = [2,7,11,15], target = 9
	Output: [1,2]
	Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
	Example 2:

	Input: numbers = [2,3,4], target = 6
	Output: [1,3]
	Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
	
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       // vector<int> ans;
        unordered_map<int,int> m;

        for(int i=0;i< numbers.size();i++)
        {
            int secondVal=target-numbers[i];
            if(m.find(secondVal)!= m.end())
            {
                return {m[secondVal]+1,i+1};
            }
            m[numbers[i]]=i;
        }
        return {-1,-1};
    }
};

Time:   O(N)
space:  O(N)
