/*28. Implement strStr()
mplement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};