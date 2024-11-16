/**
	Trapping Rain Water
	
	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
	
	
	Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
	
	https://leetcode.com/problems/trapping-rain-water/description/
	
**/

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();

        vector<int> leftVec(n);
        vector<int> rightVec(n);

        leftVec[0]=height[0];

        for(int i=1;i<n;i++)
        {
            leftVec[i]=max(height[i],leftVec[i-1]);
        }

        rightVec[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--)
        {
            rightVec[i]=max(height[i],rightVec[i+1]);
        }

        for(int i=1;i<n-1;i++)
        {
            res=res+ (min(leftVec[i],rightVec[i]) - height[i]);
        }

        return res;
    }
};


Time complexity:  O(n)
Space complexity: O(n)

