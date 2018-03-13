/*17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
*/
/*
题意：输入电话键盘上的数字串，输出对应的字母串
题解：1.迭代：
        现用的迭代，效率特别低。
        每次记录当前的字符串，然后把他清空，换成加上下一个字母的字符串；
     2.递归：
        效率提高了很多，参考别人的代码。思路还是挺好的
     3.
*/



class Solution1 {
public:
    //递归（快）
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) res.push_back(out);
        else {
            string str = dict[digits[level] - '2'];
            for (int i = 0; i < str.size(); ++i) {
                //添加字符
                out.push_back(str[i]);
                //递归到最后会将结果Push到res
                letterCombinationsDFS(digits, dict, level + 1, out, res);
                //回退到未添加前的状态，好继续添加
                out.pop_back();
            }
        }	
    }
};
//--------------------------------------------------------------------------------------------------//
class Solution2 {
public:
    //迭代（慢）
    vector<string> letterCombinations1(string digits) {
        int length = digits.size();
        vector<string> res;
        if (digits.empty())
            return res;
        string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            int n = res.size();
            string str = dict[digits[i] - '2'];
            //把已有的全部替换
            for (int j = 0; j < n; ++j) {
                string tmp = res.front();
                res.erase(res.begin());
                //对应的全部+1
                for (int k = 0; k < str.size(); ++k) {
                    res.push_back(tmp + str[k]);
                }
            }
        }
        return res;
    }
};
//------------------------------------------------------------------------------------------------------//