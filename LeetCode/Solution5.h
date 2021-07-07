/*
5. ������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

ʾ�� 1��
���룺s = "babad"
�����"bab"
���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�

ʾ�� 2��
���룺s = "cbbd"
�����"bb"

ʾ�� 3��
���룺s = "a"
�����"a"

ʾ�� 4��
���룺s = "ac"
�����"a"

��ʾ��
1 <= s.length <= 1000
s �������ֺ�Ӣ����ĸ����д��/��Сд�����
������Ӵ����ִ��ַ���Գƣ��磺"baab","bab"
*/
#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//leetcode5 Ѱ��������Ӵ�
class Solution5
{
public:
	//��������������ɢ
	string longestPalindrome1(string s);
	//��̬�滮
	string longestPalindrome2(string s);
	//manacher�㷨+������ɢ
	string longestPalindrome3(string s);
	void test();
private:
	//������ɢ
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
ִ����ʱ��40 ms, ������ C++ �ύ�л�����72.64%���û�
�ڴ����ģ�6.9 MB, ������ C++ �ύ�л�����95.37%���û�
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
		//���ż���������
		if (s[i] == s[i + 1])
		{
			l1 = i, r1 = i + 1;
			centralExpansion(s, l1, r1);
		}
		//��������������
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
ִ����ʱ��324 ms, ������ C++ �ύ�л�����49.56%���û�
�ڴ����ģ�117.7 MB, ������ C++ �ύ�л�����39.82%���û�
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
			//�Ӵ����������ַ�
			if (r - l > 1)
				dp[l][r] = (dp[l + 1][r - 1] && (s[l] == s[r]));
			//�Ӵ�ֻ�������ַ�
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
ִ����ʱ��8 ms, ������ C++ �ύ�л�����98.42%���û�
�ڴ����ģ�9 MB, ������ C++ �ύ�л�����72.76%���û�
*/
string Solution5::longestPalindrome3(string s)
{
	int s_len = s.size();
	if (s_len < 2) return s;
	
	//�����ַ���s����#ת��Ϊ�ַ���t���ϲ���ż�����Ȼ����ַ������
	string t = "#";
	for (int i = 0; i < s_len; ++i)
	{
		t += s[i];
		t += '#';
	}

	//��ʼ��������չ�۳�����
	int t_len = t.size();
	int* dp = new int[t_len];
	dp[0] = 0, dp[t_len - 1] = 0;
	for (int i = 1; i < t_len - 1; ++i)
		dp[i] = t_len;
	
	//������չ
	int center = 1, max_right = 1;
	int max_arm = 0, max_center = 0;   //��¼���ַ���t��������Ӵ���λ��
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

	//�Ƶ�ԭ�ַ��������������Ӵ��Ŀ�ʼλ�ã����Ⱥ�max_arm��С���
	int start = (max_center - 1) / 2 - (max_arm - 1) / 2;
	delete[] dp;
	return s.substr(start,max_arm);
}

void Solution5::test()
{
	cout<<longestPalindrome3("babad");
}

