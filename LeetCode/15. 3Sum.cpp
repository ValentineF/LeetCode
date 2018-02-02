/*15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
/*
题意：求三数和为0的组合
题解：其实是参考维基百科做的：
    对数组先进行排序，然后设定三个左中右的游标，固定右侧的游标为最大。
    当和小于0，移动中间游标；
    当和大于0，移动右侧游标；
    当中间游标和右侧游标相遇时，移动左侧游标；
    需要注意的是重复数组的控制
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //将数组排序
        sort(nums.begin(), nums.end());
        //固定最后一位
        int last = nums.size() - 1;
        int maxSum = nums[last] + nums[last - 1];
        for (int i = 0; i <= last-1; i++) {
            if (i > 0 && (nums[i] == nums[i - 1])) {
                continue;
            }			
            int middle = i + 1;
            int right = last;
            int first = nums[i];
            while (middle < right) {
                int second = nums[middle];
                int third = nums[right];
                int sum = first + second + third;
                if (sum == 0) {
                    result.push_back({ first, second, third });
                    while (middle < right && nums[middle] == second) {
                        middle++;
                    }
                    while (middle < right && nums[right] == third) {
                        right--;
                    }
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    middle++;
                }
            }
        }
        return result;
    }
};