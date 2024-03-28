#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include <cstring>
using namespace std;

// 直接插入排序
void InsertSort(int arr[], int length);

// 折半插入排序
void BinaryInsertSort(int arr[], int length);

// 希尔排序
void ShellsSort(int arr[], int length);

// 冒泡排序
void BubbleSort(int arr[], int length);

// 快速排序
void QuickSort(int arr[], int low, int high);

// 选择排序
void SelectSort(int arr[], int length);

// 堆排序
void heapSort(int arr[], int n);

// 归并排序
void mergeSort(vector<int>& nums, int left, int right);

// 基数排序
void radix_sort(int* a, int n);


// 归并排序链表版
// 链表节点结构体
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 合并两个有序链表
ListNode* merge(ListNode* l1, ListNode* l2);

// 归并排序链表
ListNode* sortList(ListNode* head);