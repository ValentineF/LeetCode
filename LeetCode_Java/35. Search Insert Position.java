/*35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Example 1:
Input: [1,3,5,6], 5
Output: 2*/
/* 从头到尾遍历，时间复杂度大概N*/
class SolutionA {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        for(int i = 0 ;i < length; i++){
            if(nums[i] >= target) {
                return i;
            }
        }
        return length;
    }
}
/*二分法 */
class SolutionB {
    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target){
                low = mid + 1;
            }           
            else{
                high = mid;
            }  
        }
        return low;
    }
}
