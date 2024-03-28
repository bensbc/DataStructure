#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include <cstring>
using namespace std;

// ֱ�Ӳ�������
void InsertSort(int arr[], int length);

// �۰��������
void BinaryInsertSort(int arr[], int length);

// ϣ������
void ShellsSort(int arr[], int length);

// ð������
void BubbleSort(int arr[], int length);

// ��������
void QuickSort(int arr[], int low, int high);

// ѡ������
void SelectSort(int arr[], int length);

// ������
void heapSort(int arr[], int n);

// �鲢����
void mergeSort(vector<int>& nums, int left, int right);

// ��������
void radix_sort(int* a, int n);


// �鲢���������
// ����ڵ�ṹ��
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// �ϲ�������������
ListNode* merge(ListNode* l1, ListNode* l2);

// �鲢��������
ListNode* sortList(ListNode* head);