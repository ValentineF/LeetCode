/*581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.
Example:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
/*
题目的意思就是这个数组是乱序的，需要你找出从哪里开始到哪来结束是乱序的，返回长度。
然后想了想，先用排序做，匹配出从哪来开始不一样就可以了。能AC但是，排名靠后。
应该也可以直接找，不排序
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    vector<int> source = nums;
    sort(nums.begin(),nums.end());
	int left = 0;
	int right = 0;
	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] != nums[i])
		{
			left = i;
			break;
		}
	}
	for (int j = source.size() - 1; j >= 0; j--)
	{
		if (source[j] != nums[j])
		{
			right = j;
			break;
		}
	}
    if(left == right)
    {
        return 0;
    }
    else
    {
        return right - left + 1;
    }   
    }
};