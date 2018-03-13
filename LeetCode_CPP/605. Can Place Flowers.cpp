/*605. Can Place Flowers
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, 
flowers cannot be planted in adjacent plots - they would compete for water and both would die.
Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), 
and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
 * /
 /*
 题意：给你一个连续的花盆，花不能相邻的种在一起，必需隔一个空的。现在给你可以再种多少数字N，让你判断是否合法
 解题：新加一个序列，然后放1进去，看看最多能有多少颗。在范围内的就可以拉；还有解法2，看着简单
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    vector<int> newFlowerbed = flowerbed;
	newFlowerbed.insert(newFlowerbed.begin(), 0);
	newFlowerbed.insert(newFlowerbed.end(), 0);
	
	for (int i = 1; i < newFlowerbed.size()-1; i++)
	{
		if (newFlowerbed[i - 1] == 0 && newFlowerbed[i + 1] == 0)
		{
			newFlowerbed[i] = 1;
		}
	}
	int countA = 0;
	for (int i = 0; i < flowerbed.size(); i++)
	{
		if (flowerbed[i] == 1)
		{
			countA++;
		}
	}
	int countB = 0;
	for (int i = 0; i < newFlowerbed.size(); i++)
	{
		if (newFlowerbed[i] == 1)
		{
			countB++;
		}
	}
        if(n <= countB - countA)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//这个也不错，看着简单
class Solution2 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i)
        {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
            {
                --n;
                ++i;
            }
                
        }
        return n <=0;
    }
};