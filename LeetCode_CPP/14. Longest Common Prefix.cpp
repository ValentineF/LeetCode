/*14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
		int length = strs.size();
		if (length == 0)
			return ans;
		int strFirstLen = strs[0].length();
		for (int i = 0; i < strFirstLen; i++)
		{
			char temp = strs[0][i];
			for (int j = 1; j < length; j++)
			{
				if (temp != strs[j][i])
					return ans;
			}
			ans += temp;
		}
		return ans;
    }
};