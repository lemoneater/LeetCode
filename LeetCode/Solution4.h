/*
4. Ѱ�����������������λ��
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

ʾ�� 1��
���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2

ʾ�� 2��
���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5

ʾ�� 3��
���룺nums1 = [0,0], nums2 = [0,0]
�����0.00000

ʾ�� 4��
���룺nums1 = [], nums2 = [1]
�����1.00000

ʾ�� 5��
���룺nums1 = [2], nums2 = []
�����2.00000
*/
#pragma once
#include<iostream>
#include<vector>
using namespace std;

//leetcode4 Ѱ�����������������λ��
class Solution4
{
public:
	//��������ϲ�
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    void test();
};
double Solution4::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size(), len2 = nums2.size();
    //nums1��nums2��ָ��
    int p1 = 0, p2 = 0;
    //������λ������Ҫ������������
    int count = (len1 + len2) / 2 + 1;
    double mid;
    //���������λ������Ҫ�����������
    vector<int>temp(2, 0);
    //�ϲ���������
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
    //����һ�������Ѿ��ϲ����
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