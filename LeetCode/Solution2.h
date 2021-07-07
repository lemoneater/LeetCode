/*
2. �������
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ�� 1��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[7,0,8]
���ͣ�342 + 465 = 807.

ʾ�� 2��
���룺l1 = [0], l2 = [0]
�����[0]

ʾ�� 3��
���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
�����[8,9,9,9,0,0,0,1]
*/
#pragma once
#include<iostream>
#include<vector>
using namespace std;

//������
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//leetcode2 �������
class Solution2
{
public:
	//dfs
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void test();
private:
    void ouput(ListNode* p);
    ListNode* input(vector<int> nums);
};

ListNode* Solution2::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr, * tail = nullptr;
    //��λ
    int carry = 0;
    while (l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        //��λ
        if (!head)
        {
            head = tail = new ListNode(sum % 10);
        }
        //��λ����
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    //�������һ�ν�λ
    if (carry > 0)
    {
        tail->next = new ListNode(carry);
    }
    return head;
}

inline void Solution2::ouput(ListNode* p)
{
    ListNode* t = p;
    while (t)
    {
        cout << t->val;
        t = t->next;
    }
}

inline ListNode* Solution2::input(vector<int> nums)
{
    int len = nums.size();
    ListNode* head = nullptr;
    if (len < 1) return head;
    head = new ListNode(nums[0]);
    ListNode* p = head;
    for (int i = 1; i < len; ++i)
    {
        p->next= new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

void Solution2::test()
{
    //test1
    /*vector<int> a = { 2,4,3 };
    vector<int> b = { 5,6,4 };
    ListNode* l1 = input(a);
    ListNode* l2 = input(b);
    ListNode* result = addTwoNumbers(l1, l2);
    ouput(result);*/

    //test2
    /*vector<int> a = { 0 };
    vector<int> b = { 0 };
    ListNode* l1 = input(a);
    ListNode* l2 = input(b);
    ListNode* result = addTwoNumbers(l1, l2);
    ouput(result);*/

    //test3
    vector<int> a = { 9,9,9,9,9,9,9 };
    vector<int> b = { 9,9,9,9 };
    ListNode* l1 = input(a);
    ListNode* l2 = input(b);
    ListNode* result = addTwoNumbers(l1, l2);
    ouput(result);

}