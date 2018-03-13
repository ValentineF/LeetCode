/*66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size()-1;
		if (digits[length] < 9)
		{
			digits[length]++;
			return digits;
		}		
		else
		{
			for (int i = length; i >= 0; i--)
			{
				digits[i] ++;
				if (digits[i] > 9)
				{
					digits[i] = 0;
					if (i == 0)
					{
						digits.insert(digits.begin(), 1);
						return digits;
					}
				}
				else
					break;
			}
			return digits;
		}
    }
};