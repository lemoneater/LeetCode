/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000
*/
#pragma once
#include<iostream>
#include<vector>
using namespace std;

//leetcode4 寻找两个正序数组的中位数
class Solution4
{
public:
	//有序数组合并
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    void test();
};
double Solution4::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size(), len2 = nums2.size();
    //nums1和nums2的指针
    int p1 = 0, p2 = 0;
    //计算中位数所需要的最大迭代次数
    int count = (len1 + len2) / 2 + 1;
    double mid;
    //储存计算中位数所需要的最后两个数
    vector<int>temp(2, 0);
    //合并两个数组
    while (p1 < len1 && p2 < len2 && p1 + p2 <= count)
    {
        if (nums1[p1] < nums2[p2])
        {
            ++p1;
            if (p1 + p2 == count - 1)
                temp[0] = nums1[p1 - 1];
            if (p1 + p2 == count)
                temp[1] = nums1[p1 - 1];
        }
        else
        {
            ++p2;
            if (p1 + p2 == count - 1)
                temp[0] = nums2[p2 - 1];
            if (p1 + p2 == count)
                temp[1] = nums2[p2 - 1];
        }
    }
    //其中一个数组已经合并完毕
    if (p1 + p2 < count)
    {
        int rest = count - p1 - p2;
        if (p1 < len1)
        {
            if (rest >= 2)
            {
                temp[0] = nums1[p1 + rest - 2];
                temp[1] = nums1[p1 + rest - 1];
            }
            else
                temp[1] = nums1[p1];
        }
        else
        {
            if (rest >= 2)
            {
                temp[0] = nums2[p2 + rest - 2];
                temp[1] = nums2[p2 + rest - 1];
            }
            else
                temp[1] = nums2[p2];
        }
    }
    if ((len1 + len2) % 2 == 0)
    {
        double t1 = temp[0], t2 = temp[1];
        mid = (t1 + t2) / 2;
    }
    else mid = temp[1];
    return mid;
}

void Solution4::test()
{
    //test1
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    cout << findMedianSortedArrays(nums1, nums2);

}