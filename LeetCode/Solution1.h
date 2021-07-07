/*
* 1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target的那两个整数,并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/

#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//leetcode1 两数之和(数组)
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
    //将数组信息全部存入字典(key=数字大小，value=在数组的位置)
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