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



/****************** best solution ****************/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int cnt=0;
        int length=1;
        int x;

        if (nums.size() ==0)
            return 0;

        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }

        for(auto it: s)
        {
           
            if(s.find(it-1)==s.end())
            {
               cnt=1;
               x=it;
               while(s.find(x+1)!=s.end())
               {
                    cnt=cnt+1;
                    x=x+1;
               }
                length=max(length,cnt);
            }
        }
          return length;
    }
      
};

Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
Reason: O(N) for putting all the elements into the set data structure. After that for every  starting        element, we are finding the consecutive elements. Though we are using nested loops, the set will be        traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

Space Complexity: O(N), as we are using the set data structure to solve this problem.

================================================
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

