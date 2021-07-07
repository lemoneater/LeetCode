/*
3. ���ظ��ַ�����Ӵ�
����һ���ַ����������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�

ʾ�� 1:
����: s = "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
      ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���

ʾ�� 4:
����: s = ""
���: 0
*/

#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//leetcode3 ���ظ��ַ�����ִ�
class Solution3 
{
public:
    //��������
    int lengthOfLongestSubstring(string s);
    void test();
};

int Solution3::lengthOfLongestSubstring(string s)
{
    int count = s.size();
    //��¼��Ӵ�����
    int maxlen = 0;
    //��¼��ǰ�Ӵ�����
    int templen = 0;
    //��¼��ǰ�Ӵ�
    vector<char> substring;
    //˳������ַ���ÿ���ַ�
    for (int i = 0; i < count; ++i)
    {
        auto it = find(substring.begin(), substring.end(), s[i]);
        //��ǰ�ַ��ڵ�ǰ�Ӵ��в����ڣ�������뵱ǰ�ִ�
        if (it == substring.end())
        {
            substring.push_back(s[i]);
            ++templen;
        }
        //��ǰ�ַ��ڵ�ǰ�Ӵ����Ѿ����ڣ�����ǰ�Ӵ��е�һ�γ����ظ����ַ�����֮ǰ���ַ�
        //ɾ�������¹��쵱ǰ�Ӵ�
        else
        {
            substring.erase(substring.begin(), ++it);
            substring.push_back(s[i]);
            templen = substring.size();
        }
        //�����Ӵ���󳤶�
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