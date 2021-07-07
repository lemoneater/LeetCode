/*
* 1. ����֮��
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ target������������,���������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�

ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]

ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]
*/

#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//leetcode1 ����֮��(����)
class Solution1
{
public:
    //hash
    vector<int> twoSum(vector<int>& nums, int target);
    void test();
private:
    void output(vector<int>& nums);
};

vector<int> Solution1::twoSum(vector<int>& nums, int target)
{
    int count = nums.size();
    //��������Ϣȫ�������ֵ�(key=���ִ�С��value=�������λ��)
    map<int, int> mp;
    for (int i = 0; i < count; i++)
    {
        auto it = mp.find(target - nums[i]);
        if (it != mp.end() && it->second != i)
            return { it->second,i };
        mp[nums[i]] = i;
    }
    return {};
}

inline void Solution1::output(vector<int>& nums)
{
    auto it = nums.begin();
    for (it; it < nums.end(); ++it)
    {
        cout << *it << " ";
    }
}

void Solution1::test()
{
    //test1
    vector<int> a = { 2,7,11,15 };
    vector<int> result = twoSum(a, 9);
    output(result);
}