/*3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
//厉害呀，至少我是想不到这种方法，只能说近似
/*
从左往右扩展子串，维持2个变量i和j来维持一个新的子串，j不断移动，每加入一个新的字符，判断是否有重复的，如果有重复的，移动i，生成新子串……
然后以数组代替哈希表
*/
class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};