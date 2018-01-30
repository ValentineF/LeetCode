/*53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
/*
题目：最大子列和
题解：由于题目数据结构课都讲过，用动态规划即可。注意边界的0
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum,temp;
        sum = temp = nums[0];
        if(nums.size() == 1){
            return sum;
        }
        for(int i = 1; i < nums.size(); i++){
            if(temp < 0){
                temp = nums[i];
            }
            else{
                temp += nums[i];
            }
            if(temp > sum){
                sum = temp;
            }
        }
        return sum;
    }
};
