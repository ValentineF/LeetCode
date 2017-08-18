/*7. Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/
//着实折腾了一小会儿，溢出问题还是挺严重的
class Solution {
public:
   int reverse(int x)
	{
		bool flag = false;
		if (x < 0)
             flag = true;
             
		unsigned int x1 = abs(x);
		string y;
		while (x1)
		{
			y += (x1 % 10) + '0';
			x1 /= 10;
		}
		long long int ans = 0;
		int length = y.length();
		int j = length-1;
		for (int i = 0; i < length; i++)
		{
			ans += (y[i] - '0') * pow(10, j--);
		}
		if (ans > INT32_MAX)
			return 0;
		else
		{
			if (flag)
				return -(int)ans;
			else
				return (int)ans;
		}
	}
};
//------------------------------------------------------------------------------------------------------->
//找到一个更简单的办法，觉得智商果然低下呀
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};