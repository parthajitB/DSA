/**
	https://leetcode.com/problems/circular-array-loop/description/?envType=problem-list-v2&envId=e9surc0r
	
	457. Circular Array Loop
	
	You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

	If nums[i] is positive, move nums[i] steps forward, and
	If nums[i] is negative, move nums[i] steps backward.
	Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

	A cycle in the array consists of a sequence of indices seq of length k where:

	Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
	Every nums[seq[j]] is either all positive or all negative.
	k > 1
	Return true if there is a cycle in nums, or false otherwise.
	
	Input: nums = [2,-1,1,2,2]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes are white (jumping in the same direction).


**/

