/**
Product of Array Except Self
	Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

		The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

		You must write an algorithm that runs in O(n) time and without using the division operation.

		 

		Example 1:

		Input: nums = [1,2,3,4]
		Output: [24,12,8,6]
		Example 2:

		Input: nums = [-1,1,0,-3,3]
		Output: [0,0,9,0,0]
		
https://leetcode.com/problems/product-of-array-except-self/description/		
**/

// BEST solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> rVector;
        int n=nums.size();
        int prefix[n],suffix[n];
        prefix[0]=1;

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1] * nums[i-1];
        }

        suffix[n-1]=1;

        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            rVector.push_back(prefix[i] * suffix[i]);
        }

        return rVector;

    }
};
Time Complexity: O(n)

Space Complexity: O(n) + O(n)  = O(n)

//===================================================
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();

        vector<int> v(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    v[i]=v[i]* nums[j];
                }
            }
        }
        return v;
    }
};


Time complexity:  O(n2)
space complexity:  O(1)

(Time limit exceed)



	