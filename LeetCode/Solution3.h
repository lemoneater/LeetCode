/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0
*/

#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//leetcode3 无重复字符的最长字串
class Solution3 
{
public:
    //滑动窗口
    int lengthOfLongestSubstring(string s);
    void test();
};

int Solution3::lengthOfLongestSubstring(string s)
{
    int count = s.size();
    //记录最长子串长度
    int maxlen = 0;
    //记录当前子串长度
    int templen = 0;
    //记录当前子串
    vector<char> substring;
    //顺序检索字符串每个字符
    for (int i = 0; i < count; ++i)
    {
        auto it = find(substring.begin(), substring.end(), s[i]);
        //当前字符在当前子串中不存在，则将其加入当前字串
        if (it == substring.end())
        {
            substring.push_back(s[i]);
            ++templen;
        }
        //当前字符在当前子串中已经存在，将当前子串中第一次出现重复的字符和其之前的字符
        //删除，重新构造当前子串
        else
        {
            substring.erase(substring.begin(), ++it);
            substring.push_back(s[i]);
            templen = substring.size();
        }
        //更新子串最大长度
        if (templen > maxlen)
        {
            maxlen = templen;
        }
    }
    return maxlen;
}

void Solution3::test()
{
    //test1
    cout << lengthOfLongestSubstring("abcabcbb");
}