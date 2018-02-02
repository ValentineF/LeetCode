/*16. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
/*
题意：给出一个目标值，求三个数的和最接近目标值的和
题解：原理和3Sum是类似的，也是移动游标，只是加了一个目标参数
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
	int length = nums.size();
	int min = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < length; i++) {
		int middle = i + 1;
		int right = length - 1;
		int first = nums[i];
		while (middle < right) {
			int second = nums[middle];
			int third = nums[right];
			int sum = first + second + third;
			if (sum == target) {
				return target;
			}
			else if (sum > target) {
				right--;
			}
			else {
				middle++;
			}
			if (abs(target - sum) < abs(target - min)) {
				min = sum;
			}
		}
	}
    return min;    
    }
};