/*34. Search for a Range
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = { -1,-1 };
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				ans[0] = i;
				ans[1] = i;
				break;
			}	
		}
		if (ans[0] == -1)
			return ans;
		for (int i = ans[0]+1; i < nums.size(); i++)
		{
			if (nums[i] != target)
			{
				ans[1] = i-1;
				return ans;
			}
		}
		ans[1] = nums.size()-1;
		return ans;
    }
};
//-------------------------------------------------------------------------------------------------->
//STL库函数之equal_range
vector<int> searchRange(vector<int>& nums, int target) {
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
        return {-1, -1};
    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
}
//-------------------------------------------------------------------------------------------------->
//STL库函数之lower_bound , upper_bound
vector<int> searchRange(vector<int>& nums, int target) {
    int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lo == nums.size() || nums[lo] != target)
        return {-1, -1};
    int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {lo, hi};
}