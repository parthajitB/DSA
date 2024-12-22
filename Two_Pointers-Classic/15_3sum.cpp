/**
	https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=e9snhf4h
	
	15. 3Sum
	
	Hint
	Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

	Notice that the solution set must not contain duplicate triplets.

	 

	Example 1:

	Input: nums = [-1,0,1,2,-1,-4]
	Output: [[-1,-1,2],[-1,0,1]]
	Explanation: 
	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
	The distinct triplets are [-1,0,1] and [-1,-1,2].
	Notice that the order of the output and the order of the triplets does not matter.
	Example 2:

	Input: nums = [0,1,1]
	Output: []
	Explanation: The only possible triplet does not sum up to 0.
	
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > st;

        for(int i=0;i<nums.size();i++ )
        {
            set<int>hashset;
            for( int j=i+1;j<nums.size();j++)
            {
                    int third=-(nums[i]+nums[j]);
                    if(hashset.find(third)!=hashset.end())
                    {
                        vector<int> tmp={nums[i],nums[j],third};
                        sort(tmp.begin(),tmp.end());
                        st.insert(tmp);

                    }
                    hashset.insert(nums[j]);
            }
        }

        vector<vector<int> > v(st.begin(),st.end());
        return v;
        
    }
};

Time: O(n^2)
space: O(n)