/*9. Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
//测试数据跑出来一个负数??
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int y = x;
		int z = x;
		int length = 0;
		while (y /= 10)
		{
			length++;
		}
		for (int i = 0; i < length / 2+1; i++)
		{
			int temp1 = x / pow(10, length - i);
			int temp2 = z % 10;
			if (temp1 != temp2)
				return false;
			else
			{
				x = x - temp1* pow(10, length - i);
				z /= 10;
			}			
		}
		return true;
    }
};