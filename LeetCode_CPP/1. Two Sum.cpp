/*1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		int length = nums.size();
		for (int i = 0; i < length; i++)
		{
			m[nums[i]] = i;
		}
		for (int i = 0; i < length; i++)
		{
			int ans = target - nums[i];
			if(m.find(ans)!=m.end()  && m[ans] != i)
			{
				return vector<int>{ i,m[ans] };
			}
		}
		return nums;
	}
};