/**
	Container With Most Water
	
	You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

	Find two lines that together with the x-axis form a container, such that the container contains the most water.

	Return the maximum amount of water a container can store.

	Notice that you may not slant the container.
	
	Input: height = [1,8,6,2,5,4,8,3,7]
	Output: 49
	Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
	Example 2:

	Input: height = [1,1]
	Output: 1
	
	https://leetcode.com/problems/container-with-most-water/description/
	
**/


	
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right =n-1;

        int storeArea=0;

        while(left <right)
        {
            storeArea=max(storeArea,min(height[left],height[right]) * (right-left));

            if(height[left] >  height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return storeArea;

    }
};


Time complexity:  O(n)
Space Complexity:  O(1)