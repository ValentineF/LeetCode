/*11. Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
//这个想法的基础是，如果start的长度小于end，无论如何移动end，短板在start，不可能找到比当前记录的area更大的值了，只能通过移动start来找到新的可能的更大面积。
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0, area;
        int start = 0, end = height.size() - 1;
        while (start < end) {
            if (height[start] > height[end]) {
                area = height[end] * (end - start);
                end --;
            } else {
                area = height[start] * (end - start);
                start ++;
            }
            if (area > max) {
                max = area;
            }
        }
        return max;
    }
};