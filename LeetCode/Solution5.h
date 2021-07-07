/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"

示例 3：
输入：s = "a"
输出："a"

示例 4：
输入：s = "ac"
输出："a"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成
最长回文子串：字串字符轴对称，如："baab","bab"
*/
#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//leetcode5 寻找最长回文子串
class Solution5
{
public:
	//滑动窗口中心扩散
	string longestPalindrome1(string s);
	//动态规划
	string longestPalindrome2(string s);
	//manacher算法+中心扩散
	string longestPalindrome3(string s);
	void test();
private:
	//中心扩散
	void centralExpansion(const string& s, int& l, int& r);
	void boolMaxtrix(bool** matrix, int n);
};


inline void Solution5::centralExpansion(const string& s, int& l, int& r)
{
	int len = s.size();
	while (l > 0 && r < len - 1)
	{
		if (s[l - 1] == s[r + 1])
		{
			--l;
			++r;
		}
		else break;
	}
}

/*
执行用时：40 ms, 在所有 C++ 提交中击败了72.64%的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了95.37%的用户
*/
string Solution5::longestPalindrome1(string s)
{
	int len = s.size();
	if (len < 2) return s;
	int start = 0;
	int maxlen = 1;
	for (int i = 0; i < len - 1; ++i)
	{
		int l1 = 0, r1 = 0;
		int l2 = 0, r2 = 0;
		//检查偶数长度情况
		if (s[i] == s[i + 1])
		{
			l1 = i, r1 = i + 1;
			centralExpansion(s, l1, r1);
		}
		//检查奇数长度情况
		if (i > 0 && s[i - 1] == s[i + 1])
		{
			l2 = i - 1, r2 = i + 1;
			centralExpansion(s, l2, r2);
		}
		int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
		if (len1 > len2 && len1 > maxlen)
		{
			start = l1;
			maxlen = len1;
		}
		if (len2 > len1 && len2 > maxlen)
		{
			start = l2;
			maxlen = len2;
		}
	}
	return s.substr(start,maxlen);
}

/*
执行用时：324 ms, 在所有 C++ 提交中击败了49.56%的用户
内存消耗：117.7 MB, 在所有 C++ 提交中击败了39.82%的用户
*/
string Solution5::longestPalindrome2(string s)
{
	int len = s.size();
	if (len < 2) return s;
	bool** dp = new bool*[len];
	for (int i = 0; i < len; ++i)
	{
		dp[i] = new bool[len];
		dp[i][i] = true;
	}

	int start = 0;
	int maxlen = 1;
	for (int r = 0; r < len; ++r)
	{
		for (int l = 0; l < r; l++)
		{
			//子串多于两个字符
			if (r - l > 1)
				dp[l][r] = (dp[l + 1][r - 1] && (s[l] == s[r]));
			//子串只有两个字符
			else
				dp[l][r] = (s[l] == s[r]);
			if (dp[l][r] && r - l + 1 > maxlen)
			{
				start = l;
				maxlen = r - l + 1;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return s.substr(start, maxlen);
}


inline void Solution5::boolMaxtrix(bool** matrix,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
}

/*
执行用时：8 ms, 在所有 C++ 提交中击败了98.42%的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了72.76%的用户
*/
string Solution5::longestPalindrome3(string s)
{
	int s_len = s.size();
	if (s_len < 2) return s;
	
	//整理字符串s插入#转化为字符串t，合并奇偶数长度回文字符串情况
	string t = "#";
	for (int i = 0; i < s_len; ++i)
	{
		t += s[i];
		t += '#';
	}

	//初始化中心扩展臂长数组
	int t_len = t.size();
	int* dp = new int[t_len];
	dp[0] = 0, dp[t_len - 1] = 0;
	for (int i = 1; i < t_len - 1; ++i)
		dp[i] = t_len;
	
	//中心扩展
	int center = 1, max_right = 1;
	int max_arm = 0, max_center = 0;   //记录在字符串t中最长回文子串的位置
	for (int i = 1; i < t_len - 1; ++i)
	{
		int arm, right = i, left = i;
		if (i < max_right)
		{
			arm = dp[2 * center - i] < max_right - i ? dp[2 * center - i] : max_right - i;
			right += arm;
			left -= arm;
			centralExpansion(t, left, right);
		}
		else
			centralExpansion(t, left, right);
		if (right > max_right)
		{
			center = i;
			max_right = right;
		}
		dp[i] = right - i;
		if (dp[i] > max_arm)
		{
			max_arm = dp[i];
			max_center = i;
		}
	}

	//推导原字符串出现最大回文子串的开始位置，长度和max_arm大小相等
	int start = (max_center - 1) / 2 - (max_arm - 1) / 2;
	delete[] dp;
	return s.substr(start,max_arm);
}

void Solution5::test()
{
	cout<<longestPalindrome3("babad");
}

