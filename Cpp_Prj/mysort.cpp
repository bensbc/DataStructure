#include"mysort.h"

// 直接插入排序
void InsertSort(int arr[], int length)
{
	int i = 0, j = 0, temp = 0;
	for (i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

// 折半插入排序
void BinaryInsertSort(int arr[], int length)
{
	int i, j, temp, low, mid, high = 0;
	for (i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			low = 0;
			high = i - 1;
			while (low <= high)//需要加等于号
			{
				mid = (low + high) / 2;
				if (arr[mid] > temp)
				{
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= low; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[low] = temp;
		}
	}
}

// 希尔排序
void ShellsSort(int arr[], int length)
{
	int i = 0, j = 0, temp = 0, d = length / 2;
	for (; d > 0; d = d / 2)
	{
		for (i = d; i < length; i++)
		{
			if (arr[i] < arr[i - d])
			{
				temp = arr[i];
				for (j = i - d; j >= 0 && arr[j] > temp; j = j - d)
				{
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}


// 交换两个变量的值
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 冒泡排序
void BubbleSort(int arr[], int length)
{
	bool flag = false;//是否发生交换的标志
	for (int i = 0; i < length; i++)
	{
		flag = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
}

// 快速排序
// 划分：将比基准小的值放在基准数的左边，比基准大的数放在基准数的右边，并返回基准数的下标
int partition(int arr[], int low, int high)//此处的low和high为下标
{
	int pivot = arr[high];//设置基准
	int i = low - 1;//i会“跟踪”较大者
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			Swap(arr[i], arr[j]);//交换
		}
	}
	//退出循环后，i指向的位置为大于基准数的第一个位置，直接与基准交换即可
	Swap(arr[i + 1], arr[high]);//将中枢放到应有的位置
	return i + 1;//返回基准下标
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//将当前的数组进行划分
		int mid = partition(arr, low, high);

		//跳过中枢，递归地处理左右两个部分
		QuickSort(arr, low, mid - 1);
		QuickSort(arr, mid + 1, high);
	}
}



//简单选择排序
void SelectSort(int arr[], int length)
{
	int min = 0;
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		if (min != i)
			Swap(arr[min], arr[i]);

	}
}

// 堆排序
// 交换两个指针所指向的变量的值
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 调整堆
void heapify(int arr[], int n, int i)
{
	int largest = i;		//假定根节点为最大值
	int left = 2 * i + 1;   //左孩子的下标
	int right = 2 * i + 2;  //右孩子的下标

	// 找出左右孩子以及根节点中的最大者
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);  //与左右孩子的较大者交换
		heapify(arr, n, largest);      //自上而下递归地进行堆排序
	}
}

//堆排序
void heapSort(int arr[], int n)
{
	// 从最后一个根节点开始建立初始堆，自下而上
	// 注意只能自下而上建堆，这样才能保证堆顶为最大值
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);  // 堆顶元素与未排完元素中的最后一个元素交换
		heapify(arr, i, 0);      // 调整堆
	}
}



// 归并排序
void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> temp(right - left + 1);   // 预先确定大小
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] < nums[j])
		{
			temp[k++] = nums[i++];
		}
		else
		{
			temp[k++] = nums[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}
	for (int p = 0; p < temp.size(); p++)
	{
		nums[left + p] = temp[p];    // 修改left右边的部分
	}
}

void mergeSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}


// 基数排序
// 实现10以内的数的排序
const int MAXN = 100005;
int buf[MAXN], cnt[10] = { 0 };
void radix_sort(int* a, int n) {
	int max_val = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max_val) max_val = a[i];
	}
	for (int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int idx = a[i] % 10;
		cnt[idx]++;
	}
	for (int i = 1; i < 10; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		int idx = a[i] % 10;
		buf[--cnt[idx]] = a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = buf[i];
	}
}


// 合并两个有序链表
ListNode* merge(ListNode* l1, ListNode* l2) {
	if (!l1) {
		return l2;
	}
	else if (!l2) {
		return l1;
	}
	else if (l1->val < l2->val) {
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else {
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

// 归并排序链表
ListNode* sortList(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* l2 = slow->next;
	slow->next = nullptr;
	return merge(sortList(head), sortList(l2));
}

